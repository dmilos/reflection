#ifndef reflection_object_transfer_observe
#define reflection_object_transfer_observe

// ::reflection::operation::observe_class<output_name,key_name,identifier_name>

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
         typename          output_name
        ,typename             key_name = std::string
        ,typename      identifier_name = std::string
        ,typename          report_name = bool
        ,template  < typename > class qualificator_name = std::add_const
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       class observe_class
        {
         public:
           typedef      output_name        output_type;
           typedef         key_name           key_type;
           typedef  identifier_name    identifier_type;
           typedef      report_name        report_type;

           typedef ::reflection::content::category::pure_class<identifier_type>       category_type;
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

           typedef ::reflection::operation::transfer::protocol_struct<  output_name, key_name, identifier_type, report_name, qualificator_name, container_name > protocolX_type;

           typedef typename protocolX_type::function_type     function_type;
           typedef typename protocolX_type::menu_type         menu_type;
           typedef typename protocolX_type::action_type       action_type;

           typedef std::array< function_type, 7 > control_type;
           enum control_enum
            {
              recover_not_category_index     = 0
             ,recover_missing_action_index   = 1
             ,recover_action_fail_index      = 2
             ,recover_null_pointer_index     = 3
             ,stage_prologue_index           = 4
             ,stage_stasimon_index           = 5
             ,stage_exodus_index             = 6
             };

         public:
           observe_class()
            {
             this->clear();
            }

         public:
           void clear()
            {
             this->control( recover_not_category_index   , action_type::always_true() );
             this->control( recover_missing_action_index , action_type::always_true() );
             this->control( recover_action_fail_index    , action_type::always_true() );
             this->control( recover_null_pointer_index   , action_type::always_true() );
             this->control( stage_prologue_index         , action_type::always_true() );
             this->control( stage_stasimon_index         , action_type::always_true() );
             this->control( stage_exodus_index           , action_type::always_true() );
             m_menu.clear();
            }

         public:
           control_type    const&control()const{ return m_control; }
           void                  control( control_enum const& index_param, function_type const& action_param ){ m_control[index_param] = action_param; }
           control_type        & control(){ return m_control; }
         private:
           control_type m_control;

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

              {
                auto report = this->control()[stage_prologue_index]( output_param, key_type{}, struct_param );
                if( report_type( false ) == report )
                {
                  return report;
                }
              }

             std::size_t index=0;
             for( auto iterator  =  struct_param.begin();
                       iterator !=  struct_param.end();
                     ++iterator, ++index )
              {
               auto  const            key = struct_param.key(  iterator );
               item_qualified_type   data = struct_param.data( iterator );

               if( nullptr == data.get() )
                {
                 // TODO auto report = this->control()[recover_null_pointer_index]( output_param, key, property );
                 // TODO if( report_type( false ) == report )
                 // TODO  {
                 // TODO   return report;
                 // TODO  }
                 continue;
                }

               property_qualified_reference_type   property = *( data.get() );

               category_qualified_type *  category = dynamic_cast< category_qualified_type * >( data.get() );
               if( nullptr == category )
                {
                 if( report_type( false ) == this->control()[recover_not_category_index]( output_param, key, property ) )
                  {
                   return report_type( false );
                  }
                 continue;
                }

               if( false == protocolX_type::exists( this->menu(), category->identifier() ) )
                {
                 if( report_type( false ) == this->control()[recover_missing_action_index]( output_param, key, property ) )
                  {
                   return report_type( false );
                  }
                 continue;
                }

               if( report_type( false ) == protocolX_type::find( this->menu(), category->identifier() )( output_param, key, property ) )
                {
                 if( report_type( false ) ==this->control()[recover_action_fail_index]( output_param, key, property ) )
                  {
                   return report_type( false );
                  }
                 continue;
                }

               if( index + 1 < struct_param.size() )
                {
                 auto report = this->control()[stage_stasimon_index]( output_param, key, property );
                 if( report_type( false ) == report )
                  {
                   return report;
                  }
                }

              }

             return this->control()[stage_exodus_index]( output_param, key_type{}, struct_param );
            }

       };

     }
   }
 }

#endif
