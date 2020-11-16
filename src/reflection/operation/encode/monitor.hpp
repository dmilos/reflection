#ifndef reflection_operation_encode_monitor
#define reflection_operation_encode_monitor

// ::reflection::operation::encode::scan::monitor<output_name,key_name,identifier_name,report_name,qualificator_name,container_name>

#include "../../content/category.hpp"

#include "../../type/container/container.hpp"
#include "./action.hpp"

#include "../../type/trait.hpp"

#include "./protocol.hpp"


namespace reflection
 {
  namespace operation
   {
    namespace encode
     {

      template
       <
         typename                         output_name
        ,typename                     identifier_name = std::string
        ,typename                         report_name = bool
        ,template <typename>  class qualificator_name = std::add_const
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       class monitor
        {
         public:
           typedef      output_name        output_type;
           typedef  identifier_name    identifier_type;
           typedef      report_name        report_type;
           typedef ::reflection::operation::encode::monitor<output_name,identifier_name,report_name,qualificator_name > this_type;

           typedef ::reflection::ornament::category_class<identifier_type>            category_type;
           typedef ::reflection::property::pure_class                                 property_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           typedef typename qualificator_name<  category_type >::type      category_qualified_type;
           typedef typename qualificator_name< property_type >::type       property_qualified_type;

           typedef typename std::add_lvalue_reference< property_qualified_type >::type      property_qualified_reference_type;

           typedef ::reflection::operation::encode::protocol_struct< output_name, identifier_type, report_name, qualificator_name, container_name > protocol_struct, protocol_type;

           typedef typename protocol_struct::function_type     function_type;
           typedef typename protocol_struct::menu_type         menu_type;
           typedef typename protocol_struct::action_type       action_type;

           enum recover_enum
            {
              recover__begin
             ,recover_type_acquisition_index     =  recover__begin
             ,recover_action_acquisition_index
             ,recover_action_fail_index
             ,recover__end
            };

           enum stage_enum
            {
              stage__begin = 0
             ,stage_prefix_index      //! Some action before
             ,stage_suffix_index      //! some action after
             ,stage__end
             };

           typedef std::array< function_type, recover__end > recover_array_type;
           typedef std::array< function_type, stage__end   > stage_array_type;

         public:
           monitor()
            {
             this->clear();
            }

         public:
           void clear()
            {
             this->recover( recover_type_acquisition_index   , action_type::always_true() );
             this->recover( recover_action_acquisition_index , action_type::always_true() );
             this->recover( recover_action_fail_index        , action_type::always_true() );

             this->stage( stage_prefix_index           , action_type::always_true() );
             this->stage( stage_suffix_index           , action_type::always_true() );

             this->m_menu.clear();
            }

         public:
           recover_array_type    const& recover()const{ return m_recover; }
           void                         recover( recover_enum const& index_param, function_type const& action_param ){ m_recover[index_param] = action_param; }
           recover_array_type         & recover(){ return m_recover; }
         private:
           recover_array_type m_recover;

         public:
           stage_array_type    const& stage()const{ return m_stage; }
           void                       stage( stage_enum const& index_param, function_type const& action_param ){ m_stage[index_param] = action_param; }
           stage_array_type         & stage(){ return m_stage; }
         private:
           stage_array_type m_stage;

         public:
           menu_type    const& menu()const{ return m_menu; }
           bool                menu( menu_type const& menu_param ){ m_menu = menu_param; return bool( report_type(true) ); }
         private:
           menu_type         & menu(){ return m_menu; }
           menu_type m_menu;

         public:
           void insert( identifier_type const& identifier, function_type const& function_param )
            {
             protocol_struct::insert( this->menu(), identifier, function_param );
            }

         public:
           void register__any( identifier_type const& identifier, function_type const& function_param )
            {
             protocol_struct::insert( this->menu(), identifier, function_param );
            }

          template < typename data_name >
           void register__any( function_type const& f )
            {
             auto i = identificator_type::template get<data_name>();
             this->register__any( i , f );
            }

         public:
           report_type view
            (
              output_type                       &   output_param
             ,property_qualified_reference_type   property_param
            )const
            {
             // acquisition of category
             category_qualified_type *  category = dynamic_cast< category_qualified_type * >( &property_param );
             if( nullptr == category )
              {
               auto report = this->recover()[recover_type_acquisition_index]( output_param, property_param );
               return report;
              }
             else
              {
               goto label_prefix_execute;
              }

             label_prefix_execute:
              { // prefix
               auto report = this->stage()[stage_prefix_index]( output_param, property_param );
               if( report_type( false ) == report )
                {
                 goto label_suffix_execute;
                }
               goto label_action_acquisition_execute;
              }

             // acquisition of action
             label_action_acquisition_execute:
               if( false == protocol_type::exists( this->menu(), category->identifier() ) )
                {
                 auto report = this->recover()[recover_action_acquisition_index]( output_param, property_param );
                 goto label_suffix_execute;
                }
               else
                {
                 goto label_action_execution;
                }

             label_action_execution:
              { // execution
               auto action = protocol_type::find( this->menu(), category->identifier() );

               auto report = action( output_param, property_param ); // Action exists. We can safley execute.

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
              { // recovery
               auto report = this->recover()[recover_action_fail_index]( output_param, property_param );
               if( report_type( false ) == report )
                {
                 goto label_suffix_execute;
                }
               goto label_suffix_execute;
              }

             // sufix
             label_suffix_execute:
              {
               auto report = this->stage()[stage_suffix_index]( output_param, property_param );
               return report;
              }
            }
       };

     }
   }
 }

#endif
