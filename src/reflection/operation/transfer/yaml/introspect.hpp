#ifndef reflection_operation_transfer_yaml_introspect
#define reflection_operation_transfer_yaml_introspect

// ::reflection::operation::transfer::yaml_class<output_name,key_name,type_name>

#include "../../../content/category.hpp"
#include "../../../content/function/algorithm.hpp"
#include "../../../content/typedef/typedef.hpp"
#include "../../../content/enum/enum.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/transfer/observe.hpp"





namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace yaml
       {

        template
         <
           typename      output_name //!< conect operator << ()
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct introspect_struct
          {

           public:
             typedef      output_name        output_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

           private:
             typedef std::size_t size_type;
           public:
             typedef struct context_struct
              {
                size_type m_ident=0;
                void inc(){ ++m_ident; }
                void dec(){ --m_ident; }
                void ident(){}
              }context_type;
             typedef std::shared_ptr< context_struct > contextPtr_type;
           public:
             static contextPtr_type context(){ return std::make_shared<context_struct>(); }

           public:
             typedef ::reflection::operation::transfer::yaml::introspect_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>   enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;
             typedef ::reflection::property::frienddeclaration::pure_class< identifier_type >          frienddeclaration_type;

             typedef ::reflection::ornament::relation_class             relation_type;
             typedef ::reflection::ornament::accessibility_class   accessibility_type;
             typedef ::reflection::ornament::derivation_class         derivation_type;
             typedef ::reflection::ornament::qualification_class   qualification_type;

           public:
             explicit introspect_struct( observe_type & observe_param, contextPtr_type context_param = this_type::context() )
              {
               auto context = std::make_shared<context_struct>( );
               using namespace std::placeholders;

               observe_param.control( observe_type::recover_type_acquisition_index  , &this_type::recover );
               observe_param.control( observe_type::recover_action_acquisition_index, &this_type::recover );
               observe_param.control( observe_type::recover_action_fail_index   , &this_type::recover );

               observe_param.control( observe_type::stage_introductum_index,   std::bind( &this_type::introductum, context, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_conclusio_index ,    std::bind( &this_type::conclusio,   context, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_prefix_index,                   &this_type::prefix );
               observe_param.control( observe_type::stage_suffix_index,                   &this_type::suffix );
               observe_param.control( observe_type::stage_stasimon_index ,                &this_type::stasimon );

               observe_param.insert( identificator_type::template get<       enumeration_type  >(), &this_type::enumeration       );
               observe_param.insert( identificator_type::template get<         algorithm_type  >(), &this_type::function          );
               observe_param.insert( identificator_type::template get<    typedefinition_type  >(), &this_type::typedefinition    );
               observe_param.insert( identificator_type::template get< frienddeclaration_type  >(), &this_type::frienddeclaration );
              }

           private:
             typedef    std::string       string_type;
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover    ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << std::endl;
               output_param << key_param << " : "; output_param << std::endl;
               output_param << "    "; output_param << "type"          << " : ";         output_param <<  category_type::identifier( property_param ); output_param << std::endl;
               output_param << "    "; output_param << "accesibility"  << " : ";   decoration_accessibility( output_param, property_param );           output_param << std::endl;
               output_param << "    "; output_param << "linkage"       << " : ";   decoration_linkage( output_param, property_param );                 output_param << std::endl;
               output_param << "    "; output_param << "relation"      << " : ";   decoration_relation( output_param, property_param );                output_param << std::endl;
               output_param << "    "; output_param << "qualification" << " : ";   decoration_qualification( output_param, property_param );           output_param << std::endl;
               return report_type( true );
              }

             static report_type introductum( contextPtr_type context,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  "--- "
                            << std::endl
                            << "# " << key_param;
               output_param << std::endl;
               return report_type( true );
              }

             static report_type conclusio  ( contextPtr_type context,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << std::endl;
               output_param <<  "EOF" << std::endl;
               return report_type( true );
              }

             static report_type prefix     ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;
               return report_type( result );
              }

             static report_type suffix     ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << std::endl;
               return report_type( true );
              }

             static report_type stasimon   ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               return report_type( true );
              }

             static identifier_type decoration_category( output_type & output_param, property_qualified_reference_type property_param )
              {
               return category_type::identifier( property_param );
              }

             static void decoration_accessibility  ( output_type & output_param, property_qualified_reference_type property_param)
              {
               auto accessibility_item = accessibility_type::accessibility( property_param );
               size_type count=0;
               if( accessibility_item & accessibility_type::public_index    ) { if( 0 != count )output_param << ", "; ++count; output_param << "public";   }
               if( accessibility_item & accessibility_type::private_index   ) { if( 0 != count )output_param << ", "; ++count; output_param << "private";  }
               if( accessibility_item & accessibility_type::protected_index ) { if( 0 != count )output_param << ", "; ++count; output_param << "protected";}

               if( accessibility_item & accessibility_type::direct_index   ) { if( 0 != count )output_param << ", "; ++count; output_param << "direct"; }
               if( accessibility_item & accessibility_type::inspect_index  ) { if( 0 != count )output_param << ", "; ++count; output_param << "inspect"; }
               if( accessibility_item & accessibility_type::mutate_index   ) { if( 0 != count )output_param << ", "; ++count; output_param << "mutate"; }
               if( accessibility_item & accessibility_type::exposed_index  ) { if( 0 != count )output_param << ", "; ++count; output_param << "exposed"; }
               if( accessibility_item & accessibility_type::guarded_index  ) { if( 0 != count )output_param << ", "; ++count; output_param << "guarded"; }
               if( accessibility_item & accessibility_type::variable_index ) { if( 0 != count )output_param << ", "; ++count; output_param << "variable"; }
             //if( accessibility_item & accessibility_type::trinity_index  ) { if( 0 != count )output_param << ", "; ++count; output_param << "trinity"; }
              }

             static void decoration_linkage        ( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::linkage_class linkage_type;
               auto linkage_item = linkage_type::linkage( property_param );
               switch( linkage_item )
                {
                 case( linkage_type::inline_index    ): output_param << " inline" ; break;
                 case( linkage_type::static_index    ): output_param << " static" ; break;
               //case( linkage_type::extern_index    ): output_param << " extern" ; break;
               //case( linkage_type::dll_index       ): output_param << " dll"    ; break;
               //case( linkage_type::default_index   ): output_param << " default"; break;
                }
              }

             static void decoration_relation( output_type & output_param, property_qualified_reference_type property_param)
              {
               auto relation_item = relation_type::relation( property_param );
               switch( relation_item )
                {
                 case( relation_type::friend_index   ): output_param << " "<< "friend"   << ","  <<std::endl; break;
                 case( relation_type::member_index   ): output_param << " "<< "member"   << ","  <<std::endl; break;
                 case( relation_type::derived_index  ): output_param << " "<< "derived"  << ","  <<std::endl; break;
                 case( relation_type::base_index     ): output_param << " "<< "base"     << ","  <<std::endl; break;
                 case( relation_type::injected_index ): output_param << " "<< "injected" << ","  <<std::endl; break;
                 case( relation_type::field_index    ): output_param << " "<< "field"    << ","  <<std::endl; break;
               }
              }

             static size_type decoration_qualification( output_type & output_param, property_qualified_reference_type property_param)
              {
               size_type count = 0;
               auto qualification_item = qualification_type::qualification( property_param );

               if( qualification_type::unknown_index == qualification_item )
                {
                 return count;
                }

               if( qualification_item & qualification_type::const_index )
                {
                 ++count;
                 output_param << "const";
                }

               if( qualification_item & qualification_type::volatile_index )
                {
                 if( 0 != count )  output_param << ", ";
                 ++count;
                 output_param << "volatile";
                }
               return count;
              }

             static report_type enumeration( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* context = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == context )
                {
                 return report_type( false );
                }

               output_param << "# $enum" << std::endl;
               for( std::size_t index=0; index < context->container().size(); ++index )
                {
                 output_param << "    " ; output_param << "ordinal : " << std::setw(3) << index;                                output_param << std::endl;
                 output_param << "    " ; output_param << "value   : " << std::setw(3) << context->container()[index].value();  output_param << std::endl;
                 output_param << "    " ; output_param << "name    : " << std::setw(3) << context->container()[index].name() ;  output_param << std::endl;
                 output_param << std::endl;
                }

               //output_param << std::endl;

               return report_type( true );
              }

             static report_type function ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               algorithm_type  const* context = dynamic_cast< algorithm_type const* >( &property_param );
               if( nullptr == context )
                {
                 output_param << "< note=\"Wrong type supplied.\" /> ";
                 return report_type( false );
                }

               output_param << key_param << ":";                            output_param << std::endl;
               output_param << "    type : " << "\"" << "function"<< "\"";   output_param << std::endl;
               output_param << "    "; output_param << "name"            << " : ";   output_param << key_param << " : "; output_param << std::endl;
               output_param << "    "; output_param << "type"            << " : ";   output_param << category_type::identifier( property_param ); output_param << std::endl;
               output_param << "    "; output_param << "accesibility"    << " : ";   decoration_accessibility( output_param, property_param );           output_param << std::endl;
               output_param << "    "; output_param << "linkage"         << " : ";   decoration_linkage( output_param, property_param );                 output_param << std::endl;
               output_param << "    "; output_param << "relation"        << " : ";   decoration_relation( output_param, property_param );                output_param << std::endl;
               output_param << "    "; output_param << "qualification" << " : ";     decoration_qualification( output_param, property_param );           output_param << std::endl;

               output_param << "    "<< "parameters:" << std::endl;
               for( std::size_t index=0; index < context->signature().size(); ++index )
                {
                 if( context->signature()[index].instance() == identificator_type::NAT() )
                  {
                   continue;
                  }

                 output_param << "        "; output_param << "ordinal : " << index ;                                             output_param << std::endl;
                 output_param << "        "; output_param << "type    : \"" << context->signature()[index].original() << "\" ";  output_param << std::endl;
                }

               return report_type( true );
              }

             static report_type typedefinition ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedefinition_type  const* context = dynamic_cast<         typedefinition_type const* >( &property_param );
               if( nullptr == context )
                {
                 return report_type( false );
                }

               output_param << key_param;                            output_param << std::endl;
               output_param << "    type : " << "\"" << "typedef"<< "\"";   output_param << std::endl;
               output_param << "    object : " << "\"" << context->object()<< "\"";   output_param << std::endl;
               output_param << "    name   : " << "\"" << context->name()  << "\"";    output_param << std::endl;

               return report_type( true );
              }

             static report_type frienddeclaration ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               frienddeclaration_type  const* friend_instance = dynamic_cast<         frienddeclaration_type const* >( &property_param );
               if( nullptr == friend_instance )
                {
                 return report_type( false );
                }

               output_param << "# friend: " << friend_instance->object(); output_param << std::endl;
               return report_type( true );
              }
          };

       }
     }
   }
 }

#endif
