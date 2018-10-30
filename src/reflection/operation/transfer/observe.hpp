#ifndef reflection_object_transfer_observe
#define reflection_object_transfer_observe

// ::reflection::operation::observe_class<output_name,key_name,identificator_name>

#include "../../content/category.hpp"
#include "../../property/structure.hpp"

#include "../../type/container/container.hpp"
#include "./action.hpp"

#include "../../type/trait.hpp"

#include "./protocol.hpp"


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
        ,typename   identificator_name = std::string
        ,typename   report_name = bool
        ,template  < typename > class qualificator_name = std::add_const
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       class observe_class
        {
         public:
           typedef  output_name     output_type;
           typedef     key_name        key_type;
           typedef    identificator_name       identificator_type;
           typedef   report_name    report_type;

           typedef ::reflection::content::category::pure_class<identificator_type>    category_type;
           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef typename structure_type::item_type                          item_type;
           typedef typename qualificator_name< item_type >::type               item_qualified_type;

           typedef typename qualificator_name<  category_type >::type      category_qualified_type;
           typedef typename qualificator_name< property_type >::type       property_qualified_type;
           typedef typename qualificator_name< structure_type >::type     structure_qualified_type;

           typedef typename std::add_lvalue_reference< category_qualified_type >::type      category_qualified_reference_type;
           typedef typename std::add_lvalue_reference< property_qualified_type >::type      property_qualified_reference_type;
           typedef typename std::add_lvalue_reference< structure_qualified_type >::type    structure_qualified_reference_type;

           typedef ::reflection::operation::transfer::protocol_struct<  output_name, key_name, identificator_name, report_name, qualificator_name, container_name > protocolX_type;

           typedef typename protocolX_type::function_type     function_type;
           typedef typename protocolX_type::menu_type         menu_type;

           typedef std::array< function_type, 3 > recover_type;
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
           void                  recover( recover_enum const& index_param, function_type const& action_param ){ m_recover[index_param] = action_param; }
           recover_type        & recover(){ return m_recover; }
         private:
           recover_type m_recover;

         public:
           menu_type    const&menu()const{ return m_menu; }
           bool               menu( menu_type const& menu_param ){ m_menu = menu_param; return bool( report_type(true) ); }
         private:
           menu_type        & menu(){ return m_menu; }
           menu_type m_menu;

         public:
           void insert( key_type const& key, function_type const& function )
            {
             protocolX_type::insert( this->menu(), key, function );
            }

         public:
           report_type view
            (
              output_type                      & output_param
             ,structure_qualified_reference_type struct_param
            )const
            {
             for( auto iterator  =  struct_param.begin();
                       iterator !=  struct_param.end();
                     ++iterator )
              {
               auto  const            key = struct_param.key(  iterator );
               item_qualified_type   data = struct_param.data( iterator );

               if( nullptr == data.get() )
                {
                 // TODO if( report_type( false ) == recover()[null_pointer_index]( output_param, key, property ) )
                 // TODO  {
                 // TODO   return report_type( false );
                 // TODO  }
                 continue;
                }

               property_qualified_reference_type   property = *( data.get() );

               category_qualified_type *  category = dynamic_cast< category_qualified_type * >( data.get() );
               if( nullptr == category )
                {
                 if( report_type( false ) == recover()[not_category_index]( output_param, key, property ) )
                  {
                   return report_type( false );
                  }
                 continue;
                }

               if( false == protocolX_type::exists( this->menu(), category->type() ) )
                {
                 if( report_type( false ) == recover()[missing_action_index]( output_param, key, property ) )
                  {
                   return report_type( false );
                  }
                 continue;
                }

               if( report_type( false ) == protocolX_type::find( this->menu(), category->type() )( output_param, key, property ) )
                {
                 if( report_type( false ) == recover()[action_fail_index]( output_param, key, property ) )
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
