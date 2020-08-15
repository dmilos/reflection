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
        ,template <typename>          class qualificator_name = std::add_const
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

           typedef ::reflection::operation::transfer::protocol_struct< output_name, key_name, identifier_type, report_name, qualificator_name, container_name > protocolX_type, protocol_type;

           typedef typename protocolX_type::function_type     function_type;
           typedef typename protocolX_type::menu_type         menu_type;
           typedef typename protocolX_type::action_type       action_type;

           enum control_enum
            {
           //,recover__begin
              recover_type_acquisition_index     =  0
             ,recover_action_acquisition_index
             ,recover_action_fail_index
             ,recover_null_pointer_index
             ,recover__end

           //,control__begin
             ,stage_introductum_index        //!< At the beginning of everything
             ,stage_exodus_index             //!< At the end  of everything

             ,stage_prolog_index             //!< At the beginning of (sub-)structure.
             ,stage_epilog_index             //!< at the end of (sub-)structure

             ,stage_prefix_index             //!< beginning of episodia before checking if action exists

             ,stage_suffix_index             //!< end of episodia

             ,stage_stasimon_index           //!< something in between episodia

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
             this->control( recover_type_acquisition_index   , action_type::always_true() );
             this->control( recover_action_acquisition_index , action_type::always_true() );
             this->control( recover_action_fail_index    , action_type::always_true() );
             this->control( recover_null_pointer_index   , action_type::always_true() );

             this->control( stage_introductum_index           , action_type::always_true() );
             this->control( stage_exodus_index           , action_type::always_true() );
             this->control( stage_prolog_index      , action_type::always_true() );
             this->control( stage_epilog_index        , action_type::always_true() );
             this->control( stage_prefix_index           , action_type::always_true() );
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
           item_type    const& dummy()const{ return m_dummy; }
           bool                dummy( item_type const& dummy_param ){ m_dummy = dummy_param; return bool( report_type(true) ); }
         private:
           item_type         & dummy(){ return m_dummy; }
           item_type m_dummy;

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
             this->register__any( i , f );
            }

          template < typename data_name, typename view_name >
           void register_class()
            {
             using namespace std::placeholders;
             auto f = std::bind( &this_type::view_custom<data_name, view_name>, std::ref(*this) , _1, _2, _3 );
             this->register__any< data_name >( f );
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
               auto report = this->control()[recover_type_acquisition_index]( output_param, key_param, property_param );
               return report;
              }
             else
              {
               goto label_prefix_execute;
              }

             label_prefix_execute:
              {
               auto report = this->control()[stage_prefix_index]( output_param, key_param, property_param );
               if( report_type( false ) == report )
                {
                 goto label_suffix_execute;
                }
               goto label_action_acquisition_execute;
              }

             label_action_acquisition_execute:
               if( false == protocolX_type::exists( this->menu(), category->identifier() ) )
                {
                 auto report = this->control()[recover_action_acquisition_index]( output_param, key_param, property_param );
                 goto label_suffix_execute;
                }
               else
                {
                 goto label_action_execution;
                }

             label_action_execution:
              {
               auto action = protocolX_type::find( this->menu(), category->identifier() );

               auto report = action( output_param, key_param, property_param ); // Action exists. We can safley execute.

               if( report_type( false ) == report )
                {
                 goto label_action_fail;
                }
               else
                {
                 goto label_action_succes;
                }
              }

             label_action_succes:
               goto label_suffix_execute;

             label_action_fail:
              {
               auto report = this->control()[recover_action_fail_index]( output_param, key_param, property_param );
               if( report_type( false ) == report )
                {
                 goto label_suffix_execute;
                }
               goto label_suffix_execute;
              }

             label_suffix_execute:
              {
               auto report = this->control()[stage_suffix_index]( output_param, key_param, property_param );
               return report;
              }

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
               auto report = this->control()[stage_introductum_index]( output_param, key_type{}, struct_param );
               if( report_type( false ) == report )
                { //! No need for recovery fuctions. Exodus will do the cleanup.
                 goto label_exosud;
                }
              }

              {
               auto report = this->control()[stage_prolog_index]( output_param, key_type{}, struct_param );
               if( report_type( false ) == report )
                { //! No need for recovery fuctions. Evrithing should happen in prolog and epilog will do the clean up
                 goto label_epilog;
                }
              }

             { std::size_t index = struct_param.size();
             for( auto iterator  =  struct_param.begin();
                       iterator !=  struct_param.end();
                     ++iterator, --index )
              {
               auto  const            key = struct_param.key(  iterator );
               item_qualified_type   data = struct_param.data( iterator );

               auto  property = m_dummy.get();
               if( nullptr == data.get() )
                {
                 auto report = this->control()[recover_null_pointer_index]( output_param, key, *property );
                 if( report_type( false ) == report )
                  {
                   goto label_epilog;
                  }
                 goto label_stasimon_execute;
                }
               else
                {
                 property = data.get();
                 goto label_view_execute;
                }

               label_view_execute:
                {
                 {
                  auto report = this->view( output_param, key, *property );
                  if( report = report_type( false ) )
                   {
                    goto label_epilog;
                   }
                  goto label_stasimon_execute;
                 }
                }

               label_stasimon_execute:
                 if( 1 != index )
                  {
                   auto report = this->control()[stage_stasimon_index]( output_param, key, *property );
                   if( report_type( false ) == report )
                    {
                     goto label_epilog;
                    }
                  }
              }}

             label_epilog:
              {
               auto report = this->control()[stage_epilog_index]( output_param, key_type{}, struct_param );
               goto label_exosud;
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
