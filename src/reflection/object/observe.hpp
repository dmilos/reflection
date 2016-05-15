#ifndef reflection_object_observe
#define reflection_object_observe

// ::reflection::object::observe_class<output_name,key_name,type_name>

#include "../type/category.hpp"
#include "./structure.hpp"

namespace reflection
 {
  namespace object
   {

    template
     <
       typename output_name
      ,typename    key_name = std::string
      ,typename   type_name = std::string
      ,template  < typename > class qualificator_name = std::add_const
     >
     class observe_class
      {
       public:
         typedef  output_name     output_type;
         typedef     key_name        key_type;
         typedef    type_name       type_type;

         typedef ::type::category::pure_class<type_name>           category_type;
         typedef ::reflection::property::pure_class                property_type;
         typedef ::reflection::object::structure_class<key_name>  structure_type;

         typedef typename qualificator_name<  category_type  >::type     category_qualified_type;
         typedef typename qualificator_name<  property_type  >::type     property_qualified_type;
         typedef typename qualificator_name< structure_type >::type     structure_qualified_type;

         typedef std::function< bool ( key_name const&, property_qualified_type &, output_type & ) > action_type;
         typedef std::map< type_name, action_type > protocol_type;

         typedef std::array< action_type, 3 > recover_type;
         enum recover_enum { not_category_index = 0, missing_index = 1, fail_index = 2 };

       public:
         observe_class()
          {
           recover( not_category_index, []( key_name const&, property_qualified_type &, output_type & ){ return true; } );
           recover(      missing_index, []( key_name const&, property_qualified_type &, output_type & ){ return true; } );
           recover(         fail_index, []( key_name const&, property_qualified_type &, output_type & ){ return true; } );
          }

       public:
         recover_type    const&recover()const{ return m_recover; }
         void                  recover( recover_enum const& index_param, action_type const& action_param ){ m_recover[index_param] = action_param; }
         recover_type        & recover(){ return m_recover; }
       private:
         recover_type m_recover;

       public:
         protocol_type    const&protocol()const{ return m_protocol; }
         bool                   protocol( protocol_type const& protocol_param ){ m_protocol = protocol_param; return bool( true ); }
         protocol_type        & protocol(){ return m_protocol; }
       private:
         protocol_type m_protocol;

        public:
          bool view
           (
             structure_qualified_type & struct_param
            ,output_type              &   output_param
           )const
           {
            for( auto & item : struct_param.container() )
             {
              property_qualified_type *  property = item.second.get();

              category_qualified_type *  category = dynamic_cast< category_qualified_type * >( property );
              if( nullptr == category )
               { // not category
                if( false == recover()[not_category_index]( item.first, *property, output_param ) )
                 {
                  return false;
                 }
                continue;
               }

              auto action = protocol().find( category->type() );
              if( protocol().end() == action )
               {  // miss
                if( false == recover()[missing_index]( item.first, *property, output_param ) )
                 {
                  return false;
                 }
                continue;
               }

              if( false == action->second( item.first, *property, output_param ) )
               { // fail
                if( false == recover()[fail_index]( item.first, *property, output_param ) )
                 {
                  return false;
                 }
                continue;
               }
             }

            return true;
           }

     };

   }
 }

#endif
