#ifndef reflection_operation_transfer_xml_introspect
#define reflection_operation_transfer_xml_introspect

// ::reflection::operation::transfer::xml_class<output_name,key_name,type_name>

#include "../../../content/inspect/inspect.hpp"
#include "../../../content/category.hpp"

#include "../../../content/function/algorithm.hpp"
#include "../../../content/typedef/typedef.hpp"
#include "../../../content/enum/enum.hpp"

#include "../../../property/structure.hpp"
#include "../../../operation/transfer/observe.hpp"

#include "./_common.hpp"
#include "../_common/indenting.hpp"


namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace xml
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

           public:
             typedef std::size_t size_type;
             typedef std::string string_type;

             typedef struct context_struct
              {
               public:
                 typedef ::reflection::operation::transfer::xml::_common::attribute_struct<output_type, string_type>          attribute_type;
                 typedef ::reflection::operation::transfer::xml::_common::tag_struct<output_type, string_type>          tag_type;
                 typedef ::reflection::operation::transfer::_common::indenting_class<output_type, string_type>         indent_type;

                 indent_type m_indent;
                 tag_type    m_element={ true, "e" };
                 tag_type    m_item={ true, "i"};

                 tag_type    m_parameter={ true, "parameter"};
                 attribute_type m_ordinal        ={ true, "ordinal", "" };
                 attribute_type m_value          ={ true, "value", "" };
                 attribute_type m_size           ={ true, "size", "" };

                 attribute_type m_identifier ={ true, "i" };
                 attribute_type m_name ={ true, "n" };

                 attribute_type  m_cndt{ true, "note", "Can not detect type" };
                 attribute_type  m_clnt{ true, "note", "Continue like nothing happen." };

                 string_type m_accessibility="a";
                 string_type m_linkage="a";
                 attribute_type m_qualification={ true, "q" };
                 attribute_type m_derivation={ true, "d" };
                 string_type m_relation ="r";

                //struct { string_type m_name="e"; } enum_struct;
                //struct { string_type m_name="td"; } typedef_struct;

                 tag_type m_remark  ={ true, "r"  };
                 tag_type m_note    ={ true, "note"};
                 attribute_type m_messageWTS     ={ true, "N", "Wrong type supplied" };


              }context_type;

           public:
             typedef std::shared_ptr< context_type > contextPtr_type, context_pointer_type;
             static contextPtr_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::xml::introspect_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>           enumeration_type;
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
               using namespace std::placeholders;

               observe_param.control( observe_type::stage_prolog_index,   std::bind( &this_type::prolog, context_param, _1, _2, _3 ) );

               observe_param.control( observe_type::stage_prefix_index,         std::bind( &this_type::prefix, context_param, _1, _2, _3 )      );
               observe_param.control( observe_type::stage_suffix_index,         std::bind( &this_type::suffix, context_param, _1, _2, _3 )     );

               observe_param.control( observe_type::stage_epilog_index ,    std::bind( &this_type::epilog, context_param, _1, _2, _3 )   );

                observe_param.insert( identificator_type::template get<     enumeration_type >(), std::bind( &this_type::enumeration,    context_param, _1, _2, _3 ) );
                observe_param.insert( identificator_type::template get<       algorithm_type >(), std::bind( &this_type::function,       context_param, _1, _2, _3 ) );
                observe_param.insert( identificator_type::template get<  typedefinition_type >(), std::bind( &this_type::typedefinition, context_param, _1, _2, _3 ) );

              }

           private:
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover(     contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_clnt.print( output_param );

               return report_type( true );
              }

             static report_type prolog( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.newl( output_param ); 
               context_param->m_indent.indent( output_param );
               context_param->m_element.open( output_param );
               context_param->m_indent.inc();
               return report_type( true );
              }

             static report_type epilog (  contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.dec();
               context_param->m_indent.newl( output_param );
               context_param->m_indent.indent( output_param );
               context_param->m_element.close( output_param );
               return report_type( true );
              }

             static report_type prefix(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.newl( output_param ); 
               context_param->m_indent.indent( output_param );
               context_param->m_item.template open<true>( output_param );

               context_param-> m_name.print( output_param, key_param );

               decoration_category(        context_param, output_param, property_param );
               decoration_accessibility(   context_param, output_param, property_param );
               decoration_linkage(         context_param, output_param, property_param );
               decoration_qualification(   context_param, output_param, property_param );
               decoration_derivation(      context_param, output_param, property_param );
               decoration_relation(        context_param, output_param, property_param );

               output_param << ">";
               context_param->m_indent.inc();

               return report_type( true );
              }

             static report_type suffix(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.dec(); 
               context_param->m_indent.newl( output_param );
               context_param->m_indent.indent( output_param );
               context_param->m_item.close( output_param );
               return report_type( true );
              }

             static report_type stasimon( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               return report_type( true );
              }

             static report_type decoration_category( contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               category_type const* category = dynamic_cast< category_type const* >( &property_param );
               if( nullptr != category )
                {
                 context_param->m_identifier.print( output_param, category->identifier() );
                 return report_type( true );
                }
               else
                {
                 context_param->m_cndt.print( output_param );
                 return report_type( false );
                }
               return report_type( false );
              }

             static void decoration_accessibility(   contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::accessibility_class accessibility_type;
               accessibility_type  const* accessibility = dynamic_cast< accessibility_type const* >( &property_param );
               if( nullptr == accessibility )
                {
                 return;
                }

               switch( accessibility->accessibility() )
                {
                 default:
                 case( accessibility_type::public_index    ): output_param << context_param->m_accessibility << "="<< "\"public\"" ;    break;
               //case( accessibility_type::gloabal_index   ): output_param << context_param->m_accessibility << "="<< "\"global\"";    break;
                 case( accessibility_type::protected_index ): output_param << context_param->m_accessibility << "="<< "\"protected\""; break;
                 case( accessibility_type::private_index   ): output_param << context_param->m_accessibility << "="<< "\"private\"" ;   break;
               //case( accessibility_type::default_index   ): output_param << context_param->m_accessibility << "="<< "\"default\"" ;   break;
                }

               output_param << " ";
              }

             static void decoration_linkage(         contextPtr_type  &context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::linkage_class linkage_type;
               auto linkage_item = linkage_type::linkage( property_param );
               switch( linkage_item )
                {
               //case( linkage_type::default_index   ): output_param << context_param->m_linkage << "="<< "\"default\"" ;   break;
                 case( linkage_type::inline_index    ): output_param << context_param->m_linkage << "="<< "\"inline\"" ;    break;
                 case( linkage_type::static_index    ): output_param << context_param->m_linkage << "="<< "\"static\"" ;    break;
               //case( linkage_type::extern_index    ): output_param << context_param->m_linkage << "="<< "\"extern\"" ;    break;
               //case( linkage_type::dll_index       ): output_param << context_param->m_linkage << "="<< "\"dll\"" ;       break;
               //case( linkage_type::dynamic_index   ): output_param << context_param->m_linkage << "="<< "\"dynamic\"" ;   break;
                }
               output_param << " ";
              }

             static void decoration_relation(        contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               auto relation_item = relation_type::relation( property_param );
               switch( relation_item )
                {
                 case( relation_type::friend_index   ): output_param << context_param->m_relation << "="<< "\"friend\""  ; break;
                 case( relation_type::member_index   ): output_param << context_param->m_relation << "="<< "\"member\""  ; break;
                 case( relation_type::derived_index  ): output_param << context_param->m_relation << "="<< "\"derived\"" ; break;
                 case( relation_type::base_index     ): output_param << context_param->m_relation << "="<< "\"base\""    ; break;
                 case( relation_type::injected_index ): output_param << context_param->m_relation << "="<< "\"injected\""; break;
                 case( relation_type::field_index    ): output_param << context_param->m_relation << "="<< "\"field\""   ; break;
               }
               output_param << " ";
              }

             static void decoration_qualification(   contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               auto qualification_item = qualification_type::qualification( property_param );

               if( qualification_item & qualification_type::const_index )
                {
                 context_param->m_qualification.print( output_param, "const" );
                }

               if( qualification_item & qualification_type::volatile_index )
                {
                 context_param->m_qualification.print( output_param, "volatile" );
                }
              }

             static void decoration_derivation(      contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::derivation_class derivation_type;
               derivation_type  const* derivation = dynamic_cast< derivation_type const* >( &property_param );
               if( nullptr == derivation )
                {
                 return;
                }
               switch( derivation->derivation() )
                {
                 case( derivation_type::virtual_index   ): context_param->m_derivation.print( output_param, "virtual" ); break;
                }
               output_param << " ";
              }

            public:
             static report_type   enumeration    ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* enum_instance = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == enum_instance )
                {
                 context_param->m_note.single( output_param, context_param->m_messageWTS );
                 return report_type( false );
                }

               context_param->m_indent.inc();
               for( std::size_t index=0; index < enum_instance->container().size(); ++index )
                {
                 context_param->m_indent.newl( output_param ); 
                 context_param->m_indent.indent( output_param );
                 context_param->m_parameter.template open<true>( output_param );
                 context_param->m_ordinal.print( output_param, index );
                 context_param->m_value.print( output_param, enum_instance->container()[index].value() );
                 context_param->m_name.print( output_param, enum_instance->container()[index].name() );
                 output_param << "/>";
                }
               context_param->m_indent.dec();

               return report_type( true );
              }

             static report_type   function       ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               algorithm_type  const* function_instance = dynamic_cast< algorithm_type const* >( &property_param );
               if( nullptr == function_instance )
                {
                 context_param->m_note.single( output_param, context_param->m_messageWTS );
                 return report_type( false );
                }

               context_param->m_indent.inc(); 
               for( std::size_t index=0; index < function_instance->signature().size(); ++index )
                {
                 if( function_instance->signature()[index].original()  ==  identificator_type::NAT() )
                  {
                   continue;
                  }
                  
                 context_param->m_indent.newl( output_param ); 
                 context_param->m_indent.indent( output_param );
                 context_param->m_parameter.template open<true>( output_param );
                 context_param->m_ordinal.print( output_param, index );
                 context_param->m_identifier.print( output_param, function_instance->signature()[index].original() );
                 output_param << "/>";
                }
               context_param->m_indent.dec(  );

               return report_type( true );
              }

             static report_type   typedefinition ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedefinition_type  const* typedef_instance = dynamic_cast<         typedefinition_type const* >( &property_param );
               if( nullptr == typedef_instance )
                {
                 context_param->m_note.single( output_param, context_param->m_messageWTS );
                 return report_type( false );
                }

               context_param->m_indent.newl( output_param ); 
               context_param->m_indent.indent( output_param );
               output_param << "<name   value=\"" << typedef_instance->name() << "\" />";

               context_param->m_indent.newl( output_param ); 
               context_param->m_indent.indent( output_param );
               output_param << "<object value=\"" << typedef_instance->object() << "\" />";

               return report_type( true );
              }

             static report_type frienddeclaration ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               frienddeclaration_type  const* friend_instance = dynamic_cast<         frienddeclaration_type const* >( &property_param );
               if( nullptr == friend_instance )
                {
                 output_param << "<note=\"Wrong type supplied.\" .>";
                 return report_type( false );
                }

               output_param << "<friend type=\"" << friend_instance->object() << "\" />";

               //output_param << std::endl;
               return report_type( true );
              }
         };

       }
     }
   }
 }

#endif
