#ifndef reflection_operation_transfer_json_introspect
#define reflection_operation_transfer_json_introspect

// ::reflection::operation::transfer::json_class<output_name,key_name,type_name>

#include "../../../type/name/id.hpp"

#include "../../../content/category.hpp"
#include "../../../content/function/algorithm.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/encode/observe.hpp"

#include "./context.hpp"




namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace json
       {

        template
         <
           typename      output_name //!< conect operator << ()
          ,typename  identifier_name = std::string
          ,typename         key_name = std::string
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
             typedef std::size_t   size_type;
             typedef std::string string_type;

             typedef ::reflection::operation::transfer::json::context_struct<output_name,string_type> context_type;

           public:
             typedef std::shared_ptr< context_type >  context_pointer_type;
             static context_pointer_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::json::introspect_struct<output_name,identifier_name, key_name,report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::encode::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>           enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit introspect_struct( observe_type & observe_param, context_pointer_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               observe_param.recover( observe_type::recover_type_acquisition_index , std::bind( &this_type::recover, context_param, _1, _2, _3 ) );
               {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::structure, std::ref(observe_param), context_param, _1,_2, _3 );
                auto i = identificator_type::template get<  structure_type      >();
                observe_param.insert( i, f );
                observe_param.recover( observe_type::recover_action_acquisition_index   , f );
               }
             //observe_param.recover( observe_type::recover_action_fail_index   , &this_type::recover );
               observe_param.recover( observe_type::recover_null_pointer_index  , std::bind( &this_type::null_recover, context_param, _1, _2, _3 ) );

               observe_param.stage( observe_type::stage_prolog_index,   std::bind( &this_type::prolog,   context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_epilog_index ,  std::bind( &this_type::epilog,   context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_prefix_index,   std::bind( &this_type::prefix,   context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_suffix_index,   std::bind( &this_type::suffix,   context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_stasimon_index ,std::bind( &this_type::stasimon, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< bool           >(), std::bind( &this_type::primitive<bool          >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< char           >(), std::bind( &this_type::primitive< char          >, context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned char  >(), std::bind( &this_type::primitive< unsigned char >, context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< wchar_t        >(), std::bind( &this_type::primitive< wchar_t       >, context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< std::wint_t    >(), std::bind( &this_type::primitive< std::wint_t   >, context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< char16_t       >(), std::bind( &this_type::primitive< char16_t      >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< char32_t       >(), std::bind( &this_type::primitive< char32_t      >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< std::int8_t    >(), std::bind( &this_type::primitive< std::int8_t   >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< std::int16_t   >(), std::bind( &this_type::primitive< std::int16_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< std::int32_t   >(), std::bind( &this_type::primitive< std::int32_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< std::int64_t   >(), std::bind( &this_type::primitive< std::int64_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< std::uint8_t   >(), std::bind( &this_type::primitive< std::uint8_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< std::uint16_t  >(), std::bind( &this_type::primitive< std::uint16_t >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< std::uint32_t  >(), std::bind( &this_type::primitive< std::uint32_t >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< std::uint64_t  >(), std::bind( &this_type::primitive< std::uint64_t >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<       float     >(), std::bind( &this_type::primitive<     float    >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<      double     >(), std::bind( &this_type::primitive<    double    >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  long double    >(), std::bind( &this_type::primitive<long double   >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get< short            >(), std::bind( &this_type::primitive< short              >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned short   >(), std::bind( &this_type::primitive< unsigned short     >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< int              >(), std::bind( &this_type::primitive< int                >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned         >(), std::bind( &this_type::primitive< unsigned           >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< long             >(), std::bind( &this_type::primitive< long               >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< long long        >(), std::bind( &this_type::primitive< long long          >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned long     >(), std::bind( &this_type::primitive< unsigned long      >, context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned long long>(), std::bind( &this_type::primitive< unsigned long long >, context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get< void*          >(), std::bind( &this_type::primitive<void*         >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< nullptr_t      >(), std::bind( &this_type::null_value, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< std::string   >(), std::bind( &this_type::string , context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::wstring  >(), std::bind( &this_type::wstring, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  enumeration_type     >(), std::bind( &this_type::enumeration ,   context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  algorithm_type       >(), std::bind( &this_type::function,       context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  typedefinition_type  >(), std::bind( &this_type::typedefinition, context_param, _1, _2, _3 ) );
              }

           private:
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               auto const & note_string = context_param->m_key.m_note;

               //context_param->m_indent.indent( output_param );
               output_param << "{" ;
               //context_param->m_indent.inc(); context_param->m_indent.newl(output_param); context_param->m_indent.indent( output_param );
               output_param << "\"" << note_string << "\" : " << "\"" <<  context_param->m_message.m_GR << "\"";
               //context_param->m_indent.newl(output_param); context_param->m_indent.dec(); context_param->m_indent.indent( output_param );
               output_param << "}";
               //context_param->m_indent.newl(output_param);
               return report_type( true );
              }

             static report_type null_recover( context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  "null"; context_param->m_indent.newl(output_param);
               return true;
              }

             static report_type introductum(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->m_indent.newl(output_param);
               //context_param->m_indent.indent(output_param);
               //output_param << "{";
               //context_param->m_indent.inc();
               return report_type( true );
              }

             static report_type exodus  ( context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->m_indent.newl(output_param);
               //context_param->m_indent.dec();
               //context_param->m_indent.indent(output_param);
               //output_param << "}";
               return report_type( true );
              }

             static report_type prolog(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.newl(output_param);
               context_param->m_indent.indent(output_param);
               output_param << "{";
               context_param->m_indent.newl(output_param);
               context_param->m_indent.inc();
               return report_type( true );
              }

             static report_type epilog  ( context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.newl(output_param);
               context_param->m_indent.dec();
               context_param->m_indent.indent(output_param);
               output_param << "}";
               return report_type( true );
              }

             static report_type prefix(   context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;
               context_param->m_indent.indent(output_param); output_param << "\"" << key_param << "\"" << ":" ; context_param->m_indent.newl( output_param );
               context_param->m_indent.indent(output_param); output_param << "{" ; context_param->m_indent.newl(output_param); context_param->m_indent.inc();

               decoration_category(       context_param, output_param, property_param );
               decoration_accessibility(  context_param, output_param, property_param );
               decoration_linkage(        context_param, output_param, property_param );
               decoration_qualification(  context_param, output_param, property_param );
               decoration_derivation(     context_param, output_param, property_param );
               decoration_relation(       context_param, output_param, property_param );

               auto const& value_string = context_param->m_key.m_value;

               context_param->m_indent.indent(output_param); output_param << "\"" << value_string << "\" : ";

               return report_type( result );
              }

             static report_type suffix(   context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.dec();
               context_param->m_indent.newl(output_param);
               context_param->m_indent.indent(output_param); output_param <<  "}";
               return report_type( true );
              }

             static report_type stasimon( context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  ",";
               context_param->m_indent.newl(output_param);
               return report_type( true );
              }

             static report_type decoration_category( context_pointer_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               category_type const* category = dynamic_cast< category_type const* >( &property_param );
               if( nullptr != category )
                {
                 auto const& type_string = context_param->m_key.m_type;
                 context_param->m_indent.indent(output_param);
                 output_param << "\"" << type_string << "\" : \"" << category->identifier() << "\", " ; context_param->m_indent.newl(output_param);
                 return report_type( true );
                }
               else
                {
                 auto const & note_string = context_param->m_key.m_note;
                 auto const & CnDT_string = context_param->m_message.m_CnDT;
                 context_param->m_indent.indent(output_param); output_param << "\""<< note_string << "\"  : \"" << CnDT_string << "\", " ; context_param->m_indent.newl(output_param);
                 return report_type( true );
                }
                return report_type( false );
              }

             static void decoration_accessibility(   context_pointer_type &context_param, output_type & output_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::ornament::accessibility_class accessibility_type;
               accessibility_type  const* accessibility = dynamic_cast< accessibility_type const* >( &property_param );
               if( nullptr == accessibility )
                {
                 return;
                }

               auto const & accessibility_string = context_param->m_name.m_accessibility;
               switch( accessibility->accessibility() )
                {
                 default:
                 case( accessibility_type::public_index    ): context_param->m_indent.indent(output_param); output_param << "\"" << accessibility_string <<"\": "<< "\"public\""<< ","    ; context_param->m_indent.newl(output_param); break;
               //case( accessibility_type::gloabal_index   ): context_param->m_indent.indent(output_param); output_param << "\"" << accessibility_string <<"\": "<< "\"global\""<< ","    ; context_param->m_indent.newl(output_param); break;
                 case( accessibility_type::protected_index ): context_param->m_indent.indent(output_param); output_param << "\"" << accessibility_string <<"\": "<< "\"protected\""<< "," ; context_param->m_indent.newl(output_param); break;
                 case( accessibility_type::private_index   ): context_param->m_indent.indent(output_param); output_param << "\"" << accessibility_string <<"\": "<< "\"private\""<< ","   ; context_param->m_indent.newl(output_param); break;
               //case( accessibility_type::default_index   ): context_param->m_indent.indent(output_param); output_param << "\"" << accessibility_string <<"\": "<< "\"default\""<< ","   ; context_param->m_indent.newl(output_param); break;
                }
              }

             static void decoration_linkage(       context_pointer_type &context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::linkage_class linkage_type;
               linkage_type  const* linkage = dynamic_cast< linkage_type const* >( &property_param );
               if( nullptr == linkage )
                {
                 return;
                }

               auto const & linkage_string = context_param->m_name.m_linkage;
               switch( linkage->linkage() )
                {
                 case( linkage_type::inline_index    ): context_param->m_indent.indent(output_param);output_param << "\"" << linkage_string << "\": "<< "\"inline\"" << "," ; context_param->m_indent.newl(output_param); break;
                 case( linkage_type::static_index    ): context_param->m_indent.indent(output_param);output_param << "\"" << linkage_string << "\": "<< "\"static\""<< ","  ; context_param->m_indent.newl(output_param); break;
               //case( linkage_type::extern_index    ): context_param->m_indent.indent(output_param);output_param << "\"" << linkage_string << "\": "<< "\"extern\""<< ","  ; context_param->m_indent.newl(output_param); break;
               //case( linkage_type::dll_index       ): context_param->m_indent.indent(output_param);output_param << "\"" << linkage_string << "\": "<< "\"dll\""<< ","     ; context_param->m_indent.newl(output_param); break;
               //case( linkage_type::default_index   ): context_param->m_indent.indent(output_param);output_param << "\"" << linkage_string << "\": "<< "\"default\""<< "," ; context_param->m_indent.newl(output_param); break;
                }
              }

             static void decoration_qualification( context_pointer_type &context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::qualification_class qualification_type;
               qualification_type  const* qualification = dynamic_cast< qualification_type const* >( &property_param );
               if( nullptr == qualification )
                {
                 return;
                }

               auto const & qualification_string = context_param->m_name.m_qualification;
               if( qualification->qualification() & qualification_type::const_index )
                {
                 context_param->m_indent.indent(output_param); output_param << "\"" << qualification_string << "\": "<< "\"const\"" << ","; context_param->m_indent.newl(output_param);
                }

               if( qualification->qualification() & qualification_type::volatile_index )
                {
                 context_param->m_indent.indent(output_param);output_param << "\"" << qualification_string << "\": "<< "\"volatile\""<< ","; context_param->m_indent.newl(output_param);
                }

               //switch( qualification->qualification() )
                {
               //case( qualification_type::extern_index    ): context_param->m_indent.indent(output_param); output_param << "\"" << qualification_string << "\": "<< "\"extern\""<< ","  ; context_param->m_indent.newl(output_param); break;
               //case( qualification_type::dll_index       ): context_param->m_indent.indent(output_param); output_param << "\"" << qualification_string << "\": "<< "\"dll\""<< ","     ; context_param->m_indent.newl(output_param); break;
               //case( qualification_type::default_index   ): context_param->m_indent.indent(output_param); output_param << "\"" << qualification_string << "\": "<< "\"default\""<< "," ; context_param->m_indent.newl(output_param); break;
                }
              }

             static void decoration_derivation(    context_pointer_type &context_param,output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::derivation_class derivation_type;
               derivation_type  const* derivation = dynamic_cast< derivation_type const* >( &property_param );
               if( nullptr == derivation )
                {
                 return;
                }

               auto const & derivation_string = context_param->m_name.m_derivation;
                switch( derivation->derivation() )
                 {
                  case( derivation_type::virtual_index   ): context_param->m_indent.indent(output_param); output_param << "\"" << derivation_string << "\": "<< "\"virtual\""<< ","  ; context_param->m_indent.newl(output_param); break;
                 }
              }

             static void decoration_relation(      context_pointer_type &context_param, output_type & output_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::ornament::relation_class relation_type;
               relation_type  const* relation = dynamic_cast< relation_type const* >( &property_param );
               if( nullptr == relation )
                {
                 return;
                }

               auto const & relation_string = context_param->m_name.m_relation;
               switch( relation->relation() )
                {
                 case( relation_type::friend_index   ): context_param->m_indent.indent(output_param); output_param << "\"" << relation_string <<"\": "<< "\"friend\""   << ","  ; context_param->m_indent.newl(output_param); break;
                 case( relation_type::member_index   ): context_param->m_indent.indent(output_param); output_param << "\"" << relation_string <<"\": "<< "\"member\""   << ","  ; context_param->m_indent.newl(output_param); break;
                 case( relation_type::derived_index  ): context_param->m_indent.indent(output_param); output_param << "\"" << relation_string <<"\": "<< "\"derived\""  << ","  ; context_param->m_indent.newl(output_param); break;
                 case( relation_type::base_index     ): context_param->m_indent.indent(output_param); output_param << "\"" << relation_string <<"\": "<< "\"base\""     << ","  ; context_param->m_indent.newl(output_param); break;
                 case( relation_type::injected_index ): context_param->m_indent.indent(output_param); output_param << "\"" << relation_string <<"\": "<< "\"injected\"" << ","  ; context_param->m_indent.newl(output_param); break;
                 case( relation_type::field_index    ): context_param->m_indent.indent(output_param); output_param << "\"" << relation_string <<"\": "<< "\"field\""    << ","  ; context_param->m_indent.newl(output_param); break;
                }
              }

           private:
             static report_type null_value  (      context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null )
                {
                 return report_type( false );
                }

               output_param << "\"" << key_param << "\"" << ": " <<  "null" ; context_param->m_indent.newl(output_param);
               return report_type( true );
              }

             static report_type string(          context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  output_param << "\""<<  inspect->present() << "\"";
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  output_param << "\""<<  direct_instance->disclose() << "\"";
                  return report_type( true );
                 }
               }
               {
                auto const & note_string = context_param->m_key.m_note;
                auto const & CnRtV_string = context_param->m_message.m_CnRtV;
                context_param->m_indent.indent(output_param); output_param << "\"" << note_string << "\"" << ": " << "\""<<  CnRtV_string << "\""; context_param->m_indent.newl(output_param);
               return report_type( true );
              }
              }

             static report_type wstring(         context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

           private:
             template< typename simple_name >
              static report_type primitive(      context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                {
                 typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   output_param << inspect_instance->present();
                   //context_param->m_indent.newl(output_param);
                   return report_type( true );
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   output_param << direct_instance->disclose(); // context_param->m_indent.newl(output_param);
                   return report_type( true );
                  }
                }

                {
                 auto const & note_string = context_param->m_key.m_note;
                 output_param<< "{ " << "\"" << note_string << "\" : " << "\"" << context_param->m_message.m_CnRtV << "\"" << "}"; //context_param->m_indent.newl(output_param);
                }

                return report_type( true );
               }

             static report_type enumeration(     context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* enum_instance = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == enum_instance )
                {
                 // TODO
                 return report_type( false );
                }

               context_param->m_indent.newl(output_param);
               context_param->m_indent.indent(output_param);output_param << "[" ; context_param->m_indent.newl(output_param);
               context_param->m_indent.inc();
               for( std::size_t index=0; index < enum_instance->container().size(); ++index )
                {
                 context_param->m_indent.indent(output_param);
                 output_param << "{";
                 output_param << "\"" << context_param->m_key.m_ordinal << "\": "  << std::setw(3) << index << ", ";
                 output_param << "\"" << context_param->m_key.m_value   << "\": "  << std::setw(4) << enum_instance->container()[index].value() << ", ";
                 output_param << "\"" << context_param->m_key.m_name    << "\":\"" << enum_instance->container()[index].name() << "\" ";
                 output_param << "    }";
                 if( index+1< enum_instance->container().size()) output_param << ",";
                 ; context_param->m_indent.newl(output_param);
                }

               context_param->m_indent.dec();
               context_param->m_indent.indent(output_param); output_param << "]";

               return report_type( true );
              }

           private:
             static report_type function (       context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               algorithm_type  const* function_instance = dynamic_cast< algorithm_type const* >( &property_param );
               if( nullptr == function_instance )
                {
                 // TODO
                 return report_type( false );
                }

               //output_param << "    \"parameters\": " ;
               context_param->m_indent.newl(output_param);
               context_param->m_indent.indent(output_param);output_param << "[ " ; context_param->m_indent.newl(output_param);
               context_param->m_indent.inc();
               for( std::size_t index=0; index < function_instance->signature().size(); ++index )
                {
                 if( function_instance->signature()[index].original()  == identificator_type::NAT() )
                  {
                   continue;
                  }
                 context_param->m_indent.indent(output_param); output_param << "{ ";
                 output_param << "\"ordinal\": " << std::setw(3) << index << ", ";
                 output_param << "\"type\": "   << "\""<< function_instance->signature()[index].original()  << "\" ";
               //output_param << "\"name\":\""   << function_instance->container()[index].name() << "\" ";
                 output_param << "    }";
                 if( index +1 < function_instance->signature().size() ) {  output_param << ",";  }

                 context_param->m_indent.newl(output_param);
               }
               context_param->m_indent.dec();
               context_param->m_indent.indent(output_param); output_param << "] ";
               return report_type( true );
              }

           private:
             static report_type typedefinition ( context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedefinition_type  const* typedef_instance = dynamic_cast<         typedefinition_type const* >( &property_param );
               if( nullptr == typedef_instance )
                {
                 // TODO
                 return report_type( false );
                }

               context_param->m_indent.indent(output_param); output_param << "{ " ; context_param->m_indent.newl(output_param);
               context_param->m_indent.inc();
               context_param->m_indent.indent(output_param); output_param << "\"object\": \"" << typedef_instance->object() << "\"," ; context_param->m_indent.newl(output_param);
               context_param->m_indent.indent(output_param); output_param << "\"name\"  : \""   << typedef_instance->name()   << "\"" ; context_param->m_indent.newl(output_param);
               context_param->m_indent.dec();
               context_param->m_indent.indent(output_param); output_param << "}" ; context_param->m_indent.newl(output_param);
               //context_param->m_indent.newl(output_param);
               return report_type( true );
              }

           private:
             template < typename first_name, typename second_name >
              static  report_type pair(      observe_type const& observe_param, context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                // auto f = ::reflection::content::inspect::pointer( property_param.first );
                // auto s = ::reflection::content::inspect::pointer( property_param.secon );
                //observe_param.view( output_param, f );
                //observe_param.view( output_param, s );
                return false;
               }
           public:
             template < typename first_name, typename second_name >
              static  void register_pair (     observe_type & observe_param, context_pointer_type &context_param )
               {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::template pair<first_name, second_name>, std::ref(observe_param), context_param, _1, _2, _3 );
                observe_param.template register__any< std::pair< first_name, second_name > >( f );
              }

           private:
             template < typename container1_name >
              static  report_type container         ( observe_type const& observe_param, context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                typedef container1_name container_type;
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

                context_param->m_indent.newl(output_param); context_param->m_indent.indent(output_param); output_param << "{";
                context_param->m_indent.inc();

                size_type index = 0;
                for( auto const&  item: *pointer )
                 {
                  context_param->m_indent.newl(output_param);
                  observe_param.view( output_param, key_type{ std::to_string( index++ ) }, ::reflection::content::inspect::pointer<identifier_type,typename container_type::value_type>( &item ) );
                  if( index != pointer->size() )
                   {
                    output_param << ",";
                    //context_param->m_indent.newl(output_param);
                   }
                 }

                context_param->m_indent.dec();
                context_param->m_indent.newl(output_param);
                context_param->m_indent.indent(output_param);
                output_param << "}";

                return report_type( true );
               }

           public:
             template < typename container1_name >
              static  void register_container( observe_type & observe_param, context_pointer_type &context_param )
              {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::template container<container1_name>, std::ref(observe_param), context_param, _1, _2, _3 );
                observe_param.template register__any<container1_name>( f );
               }

            public:
             template < typename map_key_name, typename map_data_name >
              static void register_map( observe_type & observe_param, context_pointer_type &context_param )
               {
               this_type::template register_pair< const map_key_name, map_data_name >( observe_param, context_param );
               this_type::template register_container< std::map<map_key_name, map_data_name> >( observe_param, context_param );
               }

           private:
             static report_type structure (      observe_type const& observe_param, context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                 auto const & note_string = context_param->m_key.m_note;
                 auto const & NaS_string = context_param->m_message.m_NaS;
                 output_param<< "{ " << "\"" << note_string << "\"" << ": " << "\""<<  NaS_string << "\"" << "}";
                }

               //context_param->m_indent.newl(output_param);
               return report_type( true );
             }

           public:
             template< typename data_name, typename function_name  >
              static void register__any( function_name const& f, observe_type & observe_param, context_pointer_type &context_param )
               {
                using namespace std::placeholders;
                return observe_param.template register__any< data_name > ( std::bind( f, context_param, _1, _2, _3 ) );
               }

           public:
             template< typename data_name, typename view_name>
              static void register_class( observe_type & observe_param, context_pointer_type &context_param )
               {
                using namespace std::placeholders;
                auto f = std::bind( &observe_type::template view_custom<data_name, view_name>, std::ref(observe_param) , _1, _2, _3 );
                observe_param.template register__any< data_name >( f );
               }

          };

       }
     }
   }
 }

#endif
