#ifndef reflection_object_transfer_observe
#define reflection_object_transfer_observe

// ::reflection::operation::observe_class<output_name,key_name,type_name>

#include "../content/category.hpp"
#include "../../property/structure.hpp"

#include "../../type/container/map.hpp"
#include "./action.hpp"

#include "../../type/trait.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename output_name
        ,typename    key_name = std::string
        ,typename   type_name = std::string
        ,typename   report_name = bool
        ,template  < typename > class qualificator_name = std::add_const
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       class observe_class
        {
         public:
           typedef  output_name     output_type;
           typedef     key_name        key_type;
           typedef    type_name       type_type;
           typedef   report_name   report_type;

           typedef ::reflection::content::category::pure_class<type_type>             category_type;
           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef typename qualificator_name<  category_type >::type      category_qualified_type;
           typedef typename qualificator_name< property_type >::type       property_qualified_type;
           typedef typename qualificator_name< structure_type >::type     structure_qualified_type;

           typedef typename std::add_lvalue_reference< category_qualified_type >::type      category_qualified_reference_type;
           typedef typename std::add_lvalue_reference< property_qualified_type >::type      property_qualified_reference_type;
           typedef typename std::add_lvalue_reference< structure_qualified_type >::type    structure_qualified_reference_type;

           typedef typename ::reflection::operation::transfer::action_struct< output_type, key_type, qualificator_name, report_type>::typedef_type action_type;

           typedef container_name< type_type, action_type > container_type;
           typedef container_type protocol_type;

           typedef std::array< action_type, 3 > recover_type;
           enum recover_enum
             {
               not_category_index   = 0
              ,missing_action_index = 1
              ,action_fail_index    = 2
              ,null_pointer_index   = 3
             };

         public:
           observe_class()
            {
             recover(    not_category_index, []( output_type &, key_type const&, property_qualified_reference_type ){ return report_type(true); } );
             recover(  missing_action_index, []( output_type &, key_type const&, property_qualified_reference_type ){ return report_type(true); } );
             recover(     action_fail_index, []( output_type &, key_type const&, property_qualified_reference_type ){ return report_type(true); } );
           //recover(    null_pointer_index, []( output_type &, key_type const&, property_qualified_reference_type ){ return report_type(true); } );
            }

         public:
           recover_type    const&recover()const{ return m_recover; }
           void                  recover( recover_enum const& index_param, action_type const& action_param ){ m_recover[index_param] = action_param; }
           recover_type        & recover(){ return m_recover; }
         private:
           recover_type m_recover;

         public:
           protocol_type    const&protocol()const{ return m_protocol; }
           bool                   protocol( protocol_type const& protocol_param ){ m_protocol = protocol_param; return bool( report_type(true) ); }
           protocol_type        & protocol(){ return m_protocol; }
         private:
           protocol_type m_protocol;

          public:
            report_type view
             (
               output_type                      & output_param
              ,structure_qualified_reference_type struct_param
             )const
             {
              for( auto & item : struct_param.container() )
               {
                auto ptr = item.second.get();
                if( nullptr == ptr )
                 {
                  // TODO if( report_type( false ) == recover()[null_pointer_index]( output_param, item.first, property ) )
                  // TODO  {
                  // TODO   return report_type( false );
                  // TODO  }
                  continue;
                 }

                property_qualified_reference_type   property = *( item.second.get() );

                category_qualified_type *  category = dynamic_cast< category_qualified_type * >( ptr );
                if( nullptr == category )
                 {
                  if( report_type( false ) == recover()[not_category_index]( output_param, item.first, property ) )
                   {
                    return report_type( false );
                   }
                  continue;
                 }

                auto action = protocol().find( category->type() );
                if( protocol().end() == action )
                 {
                  if( report_type( false ) == recover()[missing_action_index]( output_param, item.first, property ) )
                   {
                    return report_type( false );
                   }
                  continue;
                 }

                if( report_type( false ) == action->second( output_param, item.first, property ) )
                 {
                  if( report_type( false ) == recover()[action_fail_index]( output_param, item.first, property ) )
                   {
                    return report_type( false );
                   }
                  continue;
                 }
               }

              return report_type( true );
             }

       };

     }
   }
 }

#endif
