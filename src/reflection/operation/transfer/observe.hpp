#ifndef reflection_operation_transfer_observe
#define reflection_operation_transfer_observe

// ::reflection::operation::transfer::observe_class<output_name,key_name,identifier_name>

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
           typedef ::reflection::operation::transfer::observe_class<output_name,key_name,identifier_name,report_name,qualificator_name, container_name> this_type;

           typedef ::reflection::ornament::category_class<identifier_type>            category_type;
           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           typedef typename structure_type::item_type                          item_type;
           typedef typename qualificator_name< item_type >::type               item_qualified_type;

           typedef typename qualificator_name<  category_type >::type      category_qualified_type;
           typedef typename qualificator_name< property_type >::type       property_qualified_type;
           typedef typename qualificator_name< structure_type >::type     structure_qualified_type;

           typedef typename std::add_lvalue_reference< category_qualified_type >::type      category_qualified_reference_type;
           typedef typename std::add_lvalue_reference< property_qualified_type >::type      property_qualified_reference_type;
           typedef typename std::add_lvalue_reference< structure_qualified_type >::type    structure_qualified_reference_type;

           typedef ::reflection::operation::transfer::protocol_struct<  output_name, key_name, identifier_type, report_name, qualificator_name, container_name > protocolX_type, protocol_type;

           typedef typename protocolX_type::function_type     function_type;
           typedef typename protocolX_type::menu_type         menu_type;
           typedef typename protocolX_type::action_type       action_type;

           enum control_enum
            {
              recover_not_category_index     =  0
             ,recover_missing_action_index
             ,recover_action_fail_index
             ,recover_null_pointer_index

             ,stage_prolog_index             // At the beginning of everything
             ,stage_exodus_index             // at the end  of everything

             ,stage_introductum_index        // At the beginning of structure
             ,stage_conclusio_index          // at the end  of structure

             ,stage_prefix_index             // beginning of episodia before checking if action exists
             ,stage_argument_index           // beginning of episodia before action starts

             ,stage_suffix_index             // end of episodia

             ,stage_stasimon_index           // something in between episodia

             ,control__end
             };
           typedef std::array< function_type, control__end > control_type;

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
             this->control( stage_prolog_index           , action_type::always_true() );
             this->control( stage_exodus_index           , action_type::always_true() );
             this->control( stage_introductum_index      , action_type::always_true() );
             this->control( stage_conclusio_index        , action_type::always_true() );
             this->control( stage_prefix_index           , action_type::always_true() );
             this->control( stage_argument_index         , action_type::always_true() );
             this->control( stage_suffix_index           , action_type::always_true() );
             this->control( stage_stasimon_index         , action_type::always_true() );
             this->m_menu.clear();
             this->m_pass = 0;
            }

         public:
           control_type    const& control()const{ return m_control; }
           void                   control( control_enum const& index_param, function_type const& action_param ){ m_control[index_param] = action_param; }
           control_type         & control(){ return m_control; }
         private:
           control_type m_control;

         public:
           menu_type    const& menu()const{ return m_menu; }
           bool                menu( menu_type const& menu_param ){ m_menu = menu_param; return bool( report_type(true) ); }
         private:
           menu_type         & menu(){ return m_menu; }
           menu_type m_menu;

         public:
           void insert( key_type const& key, function_type const& function )
            {
             protocolX_type::insert( this->menu(), key, function );
            }

           void register__any( key_type const& key, function_type const& function )
            {
             protocolX_type::insert( this->menu(), key, function );
            }

          template < typename data_name >
           void register__any( function_type const& f )
            {
             auto i = identificator_type::template get<data_name>();
             this->insert( i , f );
            }

          template < typename data_name, typename view_name >
           void register_class()
            {
             using namespace std::placeholders;
             auto i = identificator_type::template get<data_name>();
             auto f = std::bind( &this_type::view_custom<data_name, view_name>, std::ref(*this) , _1, _2, _3 );
             this->insert( i , f );
            }

         public:
           mutable std::size_t m_pass;

         public:
           report_type view
            (
              output_type                       &   output_param
             ,key_type                     const&      key_param
             ,property_qualified_reference_type   property_param
            )const
            {
             category_qualified_type *  category = dynamic_cast< category_qualified_type * >( &property_param );
             if( nullptr == category )
              {
               if( report_type( false ) == this->control()[recover_not_category_index]( output_param, key_param, property_param ) )
                {
                 goto label_suffix;
                }
               return report_type( false );
              }

             {
              auto report = this->control()[stage_prefix_index]( output_param, key_param, property_param );
              if( report_type( false ) == report )
               {
                goto label_suffix;
               }
             }

             if( false == protocolX_type::exists( this->menu(), category->identifier() ) )
              {
               if( report_type( false ) == this->control()[recover_missing_action_index]( output_param, key_param, property_param ) )
                {
                 goto label_suffix;
                }
              }

             {
              auto report = this->control()[stage_argument_index]( output_param, key_param, property_param );
              if( report_type( false ) == report )
               {
                goto label_suffix;
               }
             }

             if( report_type( false ) == protocolX_type::find( this->menu(), category->identifier() )( output_param, key_param, property_param ) )
              {
               if( report_type( false ) ==this->control()[recover_action_fail_index]( output_param, key_param, property_param ) )
                {
                 goto label_suffix;
                }
              }

             label_suffix:
             {
              auto report = this->control()[stage_suffix_index]( output_param, key_param, property_param );
              if( report_type( false ) == report )
               {
                return report;
               }
             }

             return report_type( true );
            }

         public:
           report_type view
            (
              output_type                      & output_param
             ,structure_qualified_reference_type struct_param
            )const
            {
             if( 0 == m_pass++ )
              {
               auto report = this->control()[stage_prolog_index]( output_param, key_type{}, struct_param );
               if( report_type( false ) == report )
                {
                 goto label_exosud;
                }
              }

              {
               auto report = this->control()[stage_introductum_index]( output_param, key_type{}, struct_param );
               if( report_type( false ) == report )
                {
                 goto label_conclusio;
                }
              }

             { std::size_t index = struct_param.size();
             for( auto iterator  =  struct_param.begin();
                       iterator !=  struct_param.end();
                     ++iterator, --index )
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
               auto report = this->view( output_param, key, property );
               if( report = report_type( false ) )
                {
                 goto label_stasimon;
                }
               goto label_stasimon;

               label_stasimon:
                if( 1 != index )
                 {
                  auto report = this->control()[stage_stasimon_index]( output_param, key, property );
                  if( report_type( false ) == report )
                   {
                    goto label_conclusio;
                   }
                 }
              }}

             label_conclusio:
              {
               auto report = this->control()[stage_conclusio_index]( output_param, key_type{}, struct_param );
              }

             label_exosud:
             if( 0 == --m_pass )
              {
               auto report = this->control()[stage_exodus_index]( output_param, key_type{}, struct_param );
               if( report_type( false ) == report )
                {
                 return report;
                }
              }
             return report_type( true );
            }

         public:
          template < typename userType_name, typename reflection_name >
           report_type view_custom
            (
              output_type                       &   output_param
             ,key_type                     const&      key_param
             ,property_qualified_reference_type   property_param
            )
           {
            reflection_name view;
             {
              typedef  ::reflection::property::direct::pure_class<userType_name &>         direct_type;
              direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
              if( nullptr != direct_instance )
               {
                view.pointer( &direct_instance->disclose() );
                return this->view( output_param, view );
               }
             }

             {
              typedef ::reflection::property::inspect::pure_class<userType_name const& > inspect_type;
              auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
              if( nullptr != inspect_instance )
               {
                view.pointer( const_cast< userType_name * >( &inspect_instance->present() ) );
                return this->view( output_param, view );
               }
             }

             return report_type( false );
           }

       };

     }
   }
 }

#endif
