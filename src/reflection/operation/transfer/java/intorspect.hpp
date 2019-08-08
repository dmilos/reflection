#ifndef reflection_operation_transfer_java_introspect
#define reflection_operation_transfer_java_introspect

// ::reflection::operation::transfer::java::java_class<output_name,key_name,type_name>

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
      namespace java
       {

        template
         <
           typename      output_name
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

           public:
             typedef std::size_t size_type;
             typedef struct context_struct
              {
                size_type m_ident=0;
                void inc(){ ++m_ident; }
                void dec(){ --m_ident; }
               }context_type;

             typedef std::shared_ptr< context_type > contextPtr_type;

           public:
             static contextPtr_type context(){ return std::make_shared<context_struct>(); }

           public:
             typedef ::reflection::operation::transfer::java::introspect_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

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

           public:
             explicit introspect_struct( observe_type & observe_param, contextPtr_type context_param = this_type::context() )
              {
               observe_param.control( observe_type::recover_type_acquisition_index  , &this_type::recover );
             //observe_param.control( observe_type::recover_action_acquisition_index, &this_type::recover );
               observe_param.control( observe_type::recover_action_fail_index   , &this_type::recover );

               observe_param.control( observe_type::stage_prolog_index,   &this_type::prolog );
               observe_param.control( observe_type::stage_prefix_index,   &this_type::prefix );
               observe_param.control( observe_type::stage_suffix_index,   &this_type::suffix );
               observe_param.control( observe_type::stage_epilog_index,     &this_type::epilog   );


               observe_param.insert( identificator_type::template get<     enumeration_type  >(), &this_type::enumeration    );
               observe_param.insert( identificator_type::template get<       algorithm_type  >(), &this_type::function       );
               observe_param.insert( identificator_type::template get<  typedefinition_type  >(), &this_type::typedefinition );



              }

           private:
             typedef    std::string       string_type;
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << "; // Continue like nothing happen.";
               return report_type( true );
              }

             static report_type prolog( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;
               output_param <<  "class";

               this_type::decoration_category( output_param,  property_param );
               output_param << std::endl;

               output_param <<  "  {" << std::endl;
               return result;
              }

             static report_type epilog ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  "  };" << std::endl;
               return report_type( true );
              }

             static report_type prefix( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<"    ";
               decoration_accessibility( output_param, property_param );
               decoration_linkage( output_param, property_param );

               report_type result = true;

               {
                category_type const* category = dynamic_cast< category_type const* >( &property_param );
                if( nullptr != category )
                 {
                  if( category->identifier() == identificator_type::template get<  algorithm_type      >()  ) return report_type( true );
                  if( category->identifier() == identificator_type::template get<  typedefinition_type >()  ) return report_type( true );
                  if( category->identifier() == identificator_type::template get<  enumeration_type    >()  ) return report_type( true );

                  output_param << category->identifier() << " ";
                  result = true;
                 }
                else
                 {
                  output_param << " //! Can not detect type ";
                  result = false;
                 }
               }

               return report_type( result );
              }

             static report_type suffix( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  ";" << std::endl;
               return report_type( true );
              }

             static report_type decoration_category( output_type & output_param, property_qualified_reference_type property_param )
              {
               category_type const* category = dynamic_cast< category_type const* >( &property_param );
               if( nullptr != category )
                {
                 output_param <<  category->identifier() << "\" ";
                 return report_type( true );
                }
               else
                {
                 output_param << "//!< \"Can not detect type\" ";
                 return report_type( false );
                }
               return report_type( false );
              }

             static void decoration_accessibility( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::accessibility_class accessibility_type;
               accessibility_type  const* accessibility = dynamic_cast< accessibility_type const* >( &property_param );
               if( nullptr != accessibility )
                {
                 switch( accessibility->accessibility() )
                  {
                   default:
                   case( accessibility_type::public_index    ): output_param << "public";    break;
                 //case( accessibility_type::gloabal_index   ): output_param << "global";    break;
                   case( accessibility_type::protected_index ): output_param << "protected"; break;
                   case( accessibility_type::private_index   ): output_param << "private";   break;
                 //case( accessibility_type::default_index   ): output_param << "default";   break;
                  }
                 output_param << ": ";
                }
              }

             static void decoration_linkage( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::linkage_class linkage_type;
               linkage_type  const* linkage = dynamic_cast< linkage_type const* >( &property_param );
               if( nullptr != linkage )
                {
                 switch( linkage->linkage() )
                  {
                   case( linkage_type::inline_index    ): output_param << "inline ";    break;
                   case( linkage_type::static_index    ): output_param  << "static ";    break;
                 //case( linkage_type::extern_index    ): output_param << "extern"; break;
                 //case( linkage_type::dll_index       ): output_param << "dll";   break;
                 //case( linkage_type::default_index   ): output_param << "default";   break;
                  }
                }
              }

             static report_type null_value  ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null )
                {
                 return report_type( false );
                }

               output_param << "NULL;";

               return report_type( true );
              }







             static report_type enumeration( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* enum_instance = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == enum_instance )
                {
                 output_param << "// < note=\"Wrong type supplied.\" /> ";
                 return report_type( false );
                }

               //output_param <<  key_param;
               output_param << "enum "<< enum_instance->name() <<" { ";

               for( std::size_t index=0; index < enum_instance->container().size(); ++index )
                {
                 output_param << enum_instance->container()[index].name()  << " =  ";
                 output_param << enum_instance->container()[index].value() ;
                 if( index +1 < enum_instance->container().size() ) output_param << ",";
                }
               output_param << "} ";

               //output_param << std::endl;

               return report_type( true );
              }

             static report_type function ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               algorithm_type  const* function_instance = dynamic_cast< algorithm_type const* >( &property_param );
               if( nullptr == function_instance )
                {
                 output_param << " //!< @note \"Wrong type supplied.\" />";
                 return report_type( false );
                }

               output_param << function_instance->signature()[0].original() << " ";

               output_param << key_param <<"( " ;

               for( std::size_t index=1; index < function_instance->signature().size(); ++index )
                {
                 if( function_instance->signature()[index].original() == identificator_type::NAT() )
                  {
                   continue;
                  }

                 output_param << function_instance->signature()[index].original() ;
                 if( index + 1 < function_instance->signature().size() ) output_param <<  ", ";
                }
               output_param << ")";

               //output_param << std::endl;
               return report_type( true );
              }

             static report_type typedefinition ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedefinition_type  const* typedef_instance = dynamic_cast<         typedefinition_type const* >( &property_param );
               if( nullptr == typedef_instance )
                {
                 output_param << "<note=\"Wrong type supplied.\" .>";
                 return report_type( false );
                }

               output_param << "typedef  " << typedef_instance->object() << "  "<< typedef_instance->name();

               //output_param << std::endl;
               return report_type( true );
              }

         };

       }
     }
   }
 }

#endif
