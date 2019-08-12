#ifndef reflection_operation_transfer_xml_print
#define reflection_operation_transfer_xml_print

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
           typename      output_name
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct print_struct
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
                 typedef ::reflection::operation::transfer::xml::_common::attribute_struct<output_type, string_type> attribute_type;
                 typedef ::reflection::operation::transfer::xml::_common::tag_struct<output_type, string_type>           tag_type;
                 typedef ::reflection::operation::transfer::_common::indenting_class<output_type, string_type>        ident_type;

                 ident_type m_ident;

                 tag_type m_intro   ={ true, "xml"};
                 tag_type m_element ={ true, "e"  };
                 tag_type m_item    ={ true, "i"  };

                 tag_type m_sequence  ={ true, "s"  };

                 tag_type m_parameter = { true, "parameter"};
                 attribute_type m_ordinal        ={ true, "ordinal", "" };
                 attribute_type m_value          ={ true, "value", "" };
                 attribute_type m_size           ={ true, "size", "" };

                 attribute_type m_identifier     ={ true, "i", "" };
                 attribute_type m_key            ={ true, "k", "" };
                 attribute_type m_type           ={ true, "t", "" };
                 attribute_type m_name           ={ true, "n", "" };



                 tag_type m_remark  ={ true, "r"  };
                 tag_type m_note    ={ true, "note"};
                 attribute_type m_messageNULL    ={ true, "N", "nullptr" };
                 attribute_type m_messageNotM    ={ true, "N", "Not in the menu" };
                 attribute_type m_messageRecover ={ true, "N", "Continue like nothing happen." };
                 attribute_type m_messageCNRV    ={ true, "N", "Can not retrieve value." };
                 attribute_type m_messageCNDT    ={ true, "N", "Can not detect type." };
                 attribute_type m_messageWTS     ={ true, "N", "Wrong type supplied" };
                 attribute_type m_NULL           ={ true, "N", "" };
                 attribute_type m_NaS            ={ true, "N", "Not a structure" };
                 attribute_type m_accessibility  ={ true,  "a" };
                 attribute_type m_linkage        ={  true,  "l" };


              }context_type;

             typedef std::shared_ptr< context_type > contextPtr_type;

           public:
             static contextPtr_type context(){ return std::make_shared<context_struct>(); }

           public:
             typedef ::reflection::operation::transfer::xml::print_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

             typedef typename observe_type::protocol_type  protocol_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>           enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit print_struct( observe_type & observe_param, contextPtr_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               observe_param.control( observe_type::recover_type_acquisition_index  , std::bind( &this_type::recover, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::recover_action_acquisition_index, std::bind( &this_type::recover, context_param, _1, _2, _3 ) );

               //if(false){
               // using namespace std::placeholders;
               // auto f = std::bind( &this_type::structure, std::ref(observe_param), _1, _2, _3 );
               // observe_param.insert( identificator_type::template get<  structure_type      >(), f );
               // observe_param.control( observe_type::recover_action_acquisition_index, f );
               //}

               observe_param.control( observe_type::recover_action_fail_index   , std::bind( &this_type::recover, context_param, _1, _2, _3 ) );

               observe_param.control( observe_type::stage_introductum_index, std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_exodus_index ,     std::bind( &this_type::exodus,      context_param, _1, _2, _3 )   );
               observe_param.control( observe_type::stage_prolog_index,      std::bind( &this_type::prolog, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_epilog_index ,     std::bind( &this_type::epilog, context_param, _1, _2, _3 )   );
               observe_param.control( observe_type::stage_prefix_index,      std::bind( &this_type::prefix, context_param, std::ref(observe_param), _1, _2, _3 ) );
               observe_param.control( observe_type::stage_suffix_index,      std::bind( &this_type::suffix, context_param, std::ref(observe_param), _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  nullptr_t      >(), std::bind( &this_type::null_value, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< std::string     >(), std::bind( &this_type::primitive<std::string   >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::wstring   >(), std::bind( &this_type::wstring,                   context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  char           >(), std::bind( &this_type::primitive<char          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  unsigned char  >(), std::bind( &this_type::primitive<unsigned char >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  wchar_t        >(), std::bind( &this_type::primitive<wchar_t       >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::wint_t    >(), std::bind( &this_type::primitive<std::wint_t   >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  std::int8_t    >(), std::bind( &this_type::primitive<std::int8_t   >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::int16_t   >(), std::bind( &this_type::primitive<std::int16_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::int32_t   >(), std::bind( &this_type::primitive<std::int32_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::int64_t   >(), std::bind( &this_type::primitive<std::int64_t  >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  std::uint8_t   >(), std::bind( &this_type::primitive<std::uint8_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::uint16_t  >(), std::bind( &this_type::primitive<std::uint16_t >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::uint32_t  >(), std::bind( &this_type::primitive<std::uint32_t >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::uint64_t  >(), std::bind( &this_type::primitive<std::uint64_t >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<       float     >(), std::bind( &this_type::primitive<     float    >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<      double     >(), std::bind( &this_type::primitive<    double    >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  long double    >(), std::bind( &this_type::primitive<long double   >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  void*          >(), std::bind( &this_type::primitive<void*         >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  short          >(), std::bind( &this_type::primitive<short         >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  unsigned short >(), std::bind( &this_type::primitive<unsigned short>, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  int            >(), std::bind( &this_type::primitive<int           >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  unsigned       >(), std::bind( &this_type::primitive<unsigned      >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  long           >(), std::bind( &this_type::primitive<long          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  long long      >(), std::bind( &this_type::primitive<long long     >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned long     >(), std::bind( &this_type::primitive< unsigned long          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned long long>(), std::bind( &this_type::primitive< unsigned long long     >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< std::complex<float> >(),       std::bind( &this_type::complex< float >,       context_param, std::ref(observe_param), _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::complex<double> >(),      std::bind( &this_type::complex< double >,      context_param, std::ref(observe_param), _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::complex<long double> >(), std::bind( &this_type::complex< long double >, context_param, std::ref(observe_param), _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<     enumeration_type >(), std::bind( &this_type::enumeration,    context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<       algorithm_type >(), std::bind( &this_type::function,       context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  typedefinition_type >(), std::bind( &this_type::typedefinition, context_param, _1, _2, _3 ) );

              }

           private:
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover(     contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_remark.single( output_param, context_param->m_messageRecover );
               return report_type( true );
              }

             static report_type introductum( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_ident.newl( output_param );
               context_param->m_ident.indent( output_param ); 
               context_param->m_intro.open( output_param ); 
               context_param->m_ident.inc();
               return report_type( true );
              }

             static report_type exodus (     contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_ident.dec();
               context_param->m_ident.newl( output_param );
               context_param->m_ident.indent( output_param );
               context_param->m_intro.close( output_param );
               return report_type( true );
              }

             static report_type prolog(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_ident.newl( output_param );
               context_param->m_ident.indent( output_param ); 
               context_param->m_element.open( output_param );
               context_param->m_ident.inc();
               return report_type( true );
              }

             static report_type epilog (     contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_ident.dec();
               context_param->m_ident.newl( output_param );
               context_param->m_ident.indent( output_param );
               context_param->m_element.close( output_param );
               return report_type( true );
              }

             static report_type prefix(      contextPtr_type &context_param, observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_ident.newl( output_param ); 
               context_param->m_ident.indent( output_param );
               context_param->m_item.template open<true>( output_param );
               if( key_type{} != key_param )context_param->m_name.print( output_param, key_param );

               decoration_category( context_param, observe_param, output_param, property_param );
               decoration_accessibility(           output_param, property_param );
               decoration_linkage(                 output_param, property_param );
               decoration_qualification(           output_param, property_param );
               decoration_derivation(              output_param, property_param );
               decoration_relation(                output_param, property_param );

               output_param << ">";
               context_param->m_ident.inc();

               return report_type( true );
              }

             static report_type suffix(      contextPtr_type &context_param, observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_ident.dec(); 
               context_param->m_ident.newl( output_param );
               context_param->m_ident.indent( output_param );
               context_param->m_item.close( output_param );
               return report_type( true );
              }

             static report_type stasimon(    output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               return report_type( true );
              }

             static report_type decoration_category( contextPtr_type const&context_param, observe_type const& observe_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               category_type const* category_item = dynamic_cast< category_type const* >( &property_param );
               if( nullptr == category_item )
                {
                 //context_param->m_messageCNDT.print( output_param );
                 return report_type( false );
                }

               context_param->m_identifier.print( output_param, category_item->identifier() );

               if( false == protocol_type::exists( observe_param.menu(), category_item->identifier() ) )
                {
                 context_param-> m_messageNotM.print( output_param );
                 return report_type( false );
                }
               return report_type( true );
              }

             static void decoration_accessibility(                             output_type & output_param, property_qualified_reference_type property_param)
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
                   case( accessibility_type::public_index    ): output_param << " accessibility="<< "\"public\"" ;    break;
                 //case( accessibility_type::gloabal_index   ): output_param << " accessibility="<< "\"global\"";    break;
                   case( accessibility_type::protected_index ): output_param << " accessibility="<< "\"protected\""; break;
                   case( accessibility_type::private_index   ): output_param << " accessibility="<< "\"private\"" ;   break;
                 //case( accessibility_type::default_index   ): output_param << " accessibility="<< "\"default\"" ;   break;
                  }

               output_param << " ";
              }

             static void decoration_linkage(                                   output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::linkage_class linkage_type;
               linkage_type  const* linkage = dynamic_cast< linkage_type const* >( &property_param );
               if( nullptr == linkage )
                {
                 return;
                }
                 switch( linkage->linkage() )
                  {
                 //case( linkage_type::default_index   ): output_param << " linkage="<< "\"default\"" ;   break;
                   case( linkage_type::inline_index    ): output_param << " linkage="<< "\"inline\"" ;    break;
                   case( linkage_type::static_index    ): output_param << " linkage="<< "\"static\"" ;    break;
                 //case( linkage_type::extern_index    ): output_param << " linkage="<< "\"extern\"" ; break;
                 //case( linkage_type::dll_index       ): output_param << " linkage="<< "\"dll\"" ;   break;
                 //case( linkage_type::dynamic_index   ): output_param << " linkage="<< "\"dynamic\"" ;   break;
                  }
               output_param << " ";
              }

             static void decoration_qualification( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::qualification_class qualification_type;
               qualification_type  const* qualification = dynamic_cast< qualification_type const* >( &property_param );
               if( nullptr == qualification )
                {
                 return;
                }
               if( qualification->qualification() & qualification_type::const_index )
                {
                 output_param << "    qualification="<< "\"const\" " ;
                }

               if( qualification->qualification() & qualification_type::volatile_index )
                {
                 output_param << "    qualification="<< "\"volatile\" ";
                }

               //switch( qualification->qualification() )
                {
               //case( qualification_type::extern_index    ): output_param << "    \"qualification\": "<< "\"extern\""<< ","  <<std::endl; break;
               //case( qualification_type::dll_index       ): output_param << "    \"qualification\": "<< "\"dll\""<< "," <<std::endl;   break;
               //case( qualification_type::default_index   ): output_param << "    \"qualification\": "<< "\"default\""<< "," <<std::endl;   break;
                }
              }

             static void decoration_derivation( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::derivation_class derivation_type;
               derivation_type  const* derivation = dynamic_cast< derivation_type const* >( &property_param );
               if( nullptr == derivation )
                {
                 return;
                }
                switch( derivation->derivation() )
                 {
                 case( derivation_type::virtual_index   ): output_param << "derivation= "<< "\"virtual\""; break;
                 }
               output_param << " ";
              }

             static void decoration_relation( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::relation_class relation_type;
               relation_type  const* relation = dynamic_cast< relation_type const* >( &property_param );
               if( nullptr == relation )
                {
                 return;
                }
               switch( relation->relation() )
                {
                 case( relation_type::friend_index   ): output_param << "relation="<< "\"friend\""   ; break;
                 case( relation_type::member_index   ): output_param << "relation="<< "\"member\""   ; break;
                 case( relation_type::derived_index  ): output_param << "relation="<< "\"derived\""  ; break;
                 case( relation_type::base_index     ): output_param << "relation="<< "\"base\""     ; break;
                 case( relation_type::injected_index ): output_param << "relation="<< "\"injected\"" ; break;
                 case( relation_type::field_index    ): output_param << "relation="<< "\"field\""    ; break;
                }
               output_param << " ";
              }

            private:
             static report_type null_value(   contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null )
                {
                 context_param->m_remark.single( output_param, context_param->m_messageCNRV ); 
                 return report_type( false );
                }

               output_param << "<value content=\"null\" />"; // !< TODO <-- context_param->m_null.single( output_param, context_param->m_messageCNRV ); 

               return report_type( true );
              }

             static report_type wstring(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<wstring_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  // TODO output_param << "\""<<  inspect->present() << "\"";
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<wstring_type &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  // TODO output_param << "\""<<  direct_instance->disclose() << "\"";
                  return report_type( true );
                 }
               }

               return report_type( true );
              }

             template< typename simple_name >
              static report_type primitive(   contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                boolean_type pass = true;

                if( true == pass )
                 {
                  typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                  auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                  if( nullptr != inspect_instance )
                   {
                    output_param << inspect_instance->present();
                    pass = false;
                   }
                 }

                if( true == pass )
                 {
                  typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                  direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                  if( nullptr != direct_instance )
                   {
                    output_param << direct_instance->disclose();
                    pass = false;
                   }
                 }

                if( true == pass )
                 {
                  context_param->m_remark.single( output_param, context_param->m_messageCNRV );
                 }

                return report_type( true );
               }

            private:
             template < typename enumerator_name >
              static report_type  enumerant      ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type   property_param )
               {
                {
                 typedef ::reflection::property::inspect::pure_class<enumerator_name const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   output_param << inspect_instance->present();
                   return report_type( true );
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<enumerator_name &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   output_param << direct_instance->disclose();
                   return report_type( true );
                  }
                }

                return report_type( false );
               }

             static report_type   enumeration    ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* enum_instance = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == enum_instance )
                {
                 context_param->m_note.single( output_param, context_param->m_messageWTS );
                 return report_type( false );
                }

               context_param->m_ident.inc();
               for( std::size_t index=0; index < enum_instance->container().size(); ++index )
                {
                 context_param->m_ident.newl( output_param );
                 context_param->m_ident.indent( output_param );
                 context_param->m_parameter.template open<true>( output_param );
                 context_param->m_ordinal.print( output_param, index ); 
                 context_param->m_value.print( output_param, enum_instance->container()[index].value() );
                 context_param->m_name.print( output_param, enum_instance->container()[index].name() ); 
                 output_param << "/>";
                }
               context_param->m_ident.dec();

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

               context_param->m_ident.inc(); 
               for( std::size_t index=0; index < function_instance->signature().size(); ++index )
                {
                 if( function_instance->signature()[index].original()  ==  identificator_type::NAT() )
                  {
                   continue;
                  }

                 context_param->m_ident.newl( output_param ); 
                 context_param->m_ident.indent( output_param );
                 context_param->m_parameter.template open<true>( output_param );
                 context_param->m_ordinal.print( output_param, index );
                 context_param->m_identifier.print( output_param, function_instance->signature()[index].original() );
                 output_param << "/>";
                }
               context_param->m_ident.dec(  );

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

               context_param->m_ident.newl( output_param ); 
               context_param->m_ident.indent( output_param );
               output_param << "<name   value=\"" << typedef_instance->name() << "\" />";

               context_param->m_ident.newl( output_param ); 
               context_param->m_ident.indent( output_param );
               output_param << "<object value=\"" << typedef_instance->object() << "\" />";

               return report_type( true );
              }

             template < typename number_name >
              static  report_type complex (  contextPtr_type &context_param,  observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                typedef std::complex<number_name> complex_type;
                boolean_type pass = true;

                if( true == pass )
                {
                  typedef ::reflection::property::inspect::pure_class<complex_type const& > inspect_type;
                  auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                  if( nullptr != inspect_instance )
                  {
                    output_param << inspect_instance->present().real() << "," << inspect_instance->present().imag();
                    pass = false;
                  }
                }

                if( true == pass )
                {
                  typedef  ::reflection::property::direct::pure_class<complex_type &>         direct_type;
                  direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                  if( nullptr != direct_instance )
                  {
                    output_param << direct_instance->disclose().real() << "," << direct_instance->disclose().imag();
                    pass = false;
                  }
                }

                if( true == pass )
                 {
                  context_param->m_remark.single( output_param, context_param->m_messageCNRV );
                 }

                return report_type( true );
              }

             template < typename first_name, typename second_name >
              static  report_type pair(      contextPtr_type &context_param, observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                // auto f = ::reflection::content::inspect::pointer( property_param.first );
                // auto s = ::reflection::content::inspect::pointer( property_param.secon );
                //observe_param.view( output_param, f );
                //observe_param.view( output_param, s );
                return false;
               }

             template < typename first_name, typename second_name >
              static  report_type tuple(     contextPtr_type &context_param, observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                return false;
               }

             template < typename container_value_name >
              static  report_type container( contextPtr_type &context_param, observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                typedef container_value_name container_type;
                container_type const*pointer = nullptr;

                {
                 typedef ::reflection::property::inspect::pure_class<container_type const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   pointer = &inspect_instance->present();
                   goto print_label;
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<container_type &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   pointer = &direct_instance->disclose();
                   goto print_label;
                  }
                }

                return report_type( true );
                print_label:

                 context_param->m_ident.newl( output_param );
                 context_param->m_ident.indent( output_param );
                 context_param->m_sequence.template open<true>( output_param );
                 context_param->m_size.print( output_param, pointer->size());
                 output_param << ">";
                 context_param->m_ident.inc(); 
                 for( auto const&  item: *pointer )
                  {
                   observe_param.view( output_param, key_type{}, ::reflection::content::inspect::pointer<identifier_type,typename container_type::value_type>( &item ) );
                  }
                 context_param->m_ident.dec(); 
                 context_param->m_ident.newl( output_param );
                 context_param->m_ident.indent( output_param );
                 context_param->m_sequence.close( output_param );
                 return report_type( true );
               }

             static  report_type  structureX( contextPtr_type &context_param, observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param  )
              {
               boolean_type pass = true;

               if( true == pass )
                {
                 typedef  ::reflection::property::inspect::pure_class<structure_type const&>         inspect_type;
                 inspect_type const*inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   observe_param.view( output_param, inspect_instance->present() );
                   pass = false;
                  }
                 }

               if( true == pass )
                {
                 typedef  ::reflection::property::direct::pure_class<structure_type &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   observe_param.view( output_param, direct_instance->disclose() );
                   pass = false;
                  }
                }

               if( true == pass )
                {
                 context_param->m_note.single( output_param, context_param->m_NaS );
                }

               return report_type( true );
              }

           public:
             template< typename      enum_name>
              static void register_enum(       observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< enum_name >();
                auto f = std::bind( &this_type::template enumerant<enum_name>, context_param, _1, _2, _3 );
                observe_param.register__any( i, f );
               }

             template < typename number_name >
              static  void register_complex (  observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< std::complex< number_name> >();
                auto f = std::bind( &this_type::template complex<number_name>, context_param, std::ref(observe_param), _1, _2, _3 );
                observe_param.register__any( i, f );
              }

             template < typename first_name, typename second_name >
              static  void register_pair (     observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< std::pair< first_name, second_name > >();
                auto f = std::bind( &this_type::template pair<first_name, second_name>, context_param, std::ref(observe_param),  _1, _2, _3 );
                observe_param.register__any( i, f );
              }

             template < typename first_name, typename second_name >
              static  void register_tuple(     observe_type & observe_param, contextPtr_type &context_param )
               {
                // TODO
               }

             template < typename container_value_name >
              static  void register_container( observe_type & observe_param, contextPtr_type &context_param )
               {
                typedef container_value_name container_type;
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< container_type >();
                auto f = std::bind( &this_type::template container<container_type>, context_param, std::ref(observe_param), _1, _2, _3 );
                observe_param.register__any( i , f );
               }

             template < typename map_key_name, typename map_data_name >
              static  void register_map(       observe_type & observe_param, contextPtr_type &context_param )
               {
               this_type::template register_pair< map_key_name, map_data_name >( observe_param, context_param );
               this_type::template register_container< std::map<map_key_name, map_data_name> >( observe_param, context_param );;
              }

             template< typename data_name, typename view_name>
              static void register_class(      observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< data_name >();
                auto f = std::bind( &observe_type::template view_custom<data_name, view_name>, std::ref(observe_param) , _1, _2, _3 );
                observe_param.register__any( i , f );
               }

         };

       }
     }
   }
 }

#endif
