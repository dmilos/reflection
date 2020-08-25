#ifndef reflection_operation_transfer_json_serialize
#define reflection_operation_transfer_json_serialize

// ::reflection::operation::transfer::json_class<output_name,key_name,type_name>

#include "../../../type/name/id.hpp"

#include "../../../content/category.hpp"

#include "../../../content/function/algorithm.hpp"
#include "../../../content/typedef/typedef.hpp"
#include "../../../content/enum/enum.hpp"

#include "../../../property/structure.hpp"
#include "../../../operation/transfer/observe.hpp"

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
           typename      output_name //!< connect operator << ()
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct serialize_struct
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
             typedef std::shared_ptr< context_type > contextPtr_type, context_pointer_type;
             static contextPtr_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::json::serialize_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

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
             explicit serialize_struct( observe_type & observe_param, contextPtr_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               observe_param.control( observe_type::recover_type_acquisition_index  , std::bind( &this_type::recover,   context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::recover_action_acquisition_index, std::bind( &this_type::recover,   context_param, _1, _2, _3 ) );
             //observe_param.control( observe_type::recover_action_fail_index,        std::bind( &this_type::recover,   context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::recover_null_pointer_index  , &this_type::null_recover    );

               observe_param.control( observe_type::stage_introductum_index, std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_exodus_index ,     std::bind( &this_type::exodus,      context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_prolog_index,      std::bind( &this_type::prolog,      context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_epilog_index ,     std::bind( &this_type::epilog,      context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_prefix_index,      std::bind( &this_type::prefix,      context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_suffix_index,      std::bind( &this_type::suffix,      context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_stasimon_index ,   std::bind( &this_type::stasimon,    context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  nullptr_t      >(), std::bind( &this_type::null_value, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  std::string   >(), std::bind( &this_type::string,   context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::wstring  >(), std::bind( &this_type::wstring,   context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  bool           >(), std::bind(&this_type::primitive<bool          >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  char           >(), std::bind(&this_type::primitive<char          >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  unsigned char  >(), std::bind(&this_type::primitive<unsigned char >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  wchar_t        >(), std::bind(&this_type::primitive<wchar_t       >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::wint_t    >(), std::bind(&this_type::primitive<std::wint_t   >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<  std::int8_t    >(), std::bind(&this_type::primitive<std::int8_t   >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::int16_t   >(), std::bind(&this_type::primitive<std::int16_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::int32_t   >(), std::bind(&this_type::primitive<std::int32_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::int64_t   >(), std::bind(&this_type::primitive<std::int64_t  >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<  std::uint8_t   >(), std::bind(&this_type::primitive<std::uint8_t  >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::uint16_t  >(), std::bind(&this_type::primitive<std::uint16_t >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::uint32_t  >(), std::bind(&this_type::primitive<std::uint32_t >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  std::uint64_t  >(), std::bind(&this_type::primitive<std::uint64_t >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<       float     >(), std::bind(&this_type::primitive<     float    >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<       double    >(), std::bind(&this_type::primitive<    double    >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  long double    >(), std::bind(&this_type::primitive<long double   >,  context_param,_1,_2,_3));

               observe_param.insert( identificator_type::template get<  void*          >(), std::bind(&this_type::primitive<void*         >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  short          >(), std::bind(&this_type::primitive<short         >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  unsigned short >(), std::bind(&this_type::primitive<unsigned short>,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  int            >(), std::bind(&this_type::primitive<int           >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  unsigned       >(), std::bind(&this_type::primitive<unsigned      >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  long           >(), std::bind(&this_type::primitive<long          >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get<  long long      >(), std::bind(&this_type::primitive<long long     >,  context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned long     >(), std::bind(&this_type::primitive< unsigned long      >, context_param,_1,_2,_3));
               observe_param.insert( identificator_type::template get< unsigned long long>(), std::bind(&this_type::primitive< unsigned long long >, context_param,_1,_2,_3));

               {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::structure, std::ref(observe_param), context_param, _1, _2, _3 );
                auto i = identificator_type::template get<  structure_type      >();
                observe_param.insert( i, f );
               }

              }

           private:
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               auto const & note_string = context_param->m_key.m_note;

               //context_param->m_indent.indent( output_param );
               output_param << "{ " ;
               //context_param->m_indent.inc(); context_param->m_indent.newl(output_param); context_param->m_indent.indent( output_param );
               output_param << "\"" << note_string << "\" : " << "\"" <<  context_param->m_message.m_GR << "\"";
               //context_param->m_indent.newl(output_param); context_param->m_indent.dec(); context_param->m_indent.indent( output_param );
               output_param << "}";
               //context_param->m_indent.newl(output_param);
               return report_type( true );
              }

             static report_type null_recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  "null" ; // TODO context_param->m_indent.newl(output_param);
               return true;
              }

             static report_type introductum(   contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->m_indent.newl(output_param);
               //context_param->m_indent.indent(output_param);
               //output_param << "{";
               //context_param->m_indent.inc();
               return report_type( true );
              }

             static report_type exodus  ( contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->m_indent.newl(output_param);
               //context_param->m_indent.dec();
               //context_param->m_indent.indent(output_param);
               //output_param << "}";
               return report_type( true );
              }

             static report_type prolog( contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.newl(output_param);
               context_param->m_indent.indent(output_param);
               output_param << "{" ;
               context_param->m_indent.newl(output_param);
               context_param->m_indent.inc();
               return report_type( true );
              }

             static report_type epilog  ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->m_indent.newl(output_param);
               context_param->m_indent.dec();
               context_param->m_indent.indent(output_param);
               output_param << "}";
               return report_type( true );
              }

             static report_type prefix(   contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;

               {
                category_type const* category = dynamic_cast< category_type const* >( &property_param );
                if( nullptr != category )
                 {
                  if( category->identifier() == identificator_type::template get<  algorithm_type      >()  ) { context_param->m_skip = true; return report_type( true ); }
                  if( category->identifier() == identificator_type::template get<  typedefinition_type >()  ) { context_param->m_skip = true; return report_type( true ); }
                  if( category->identifier() == identificator_type::template get<  enumeration_type    >()  ) { context_param->m_skip = true; return report_type( true ); }
                 }
                else
                 {
                  auto const & note_string = context_param->m_key.m_note;
                  auto const & CnDT_string = context_param->m_message.m_CnDT;
                  context_param->m_indent.indent(output_param); output_param << "\""<< note_string << "\"  : \"" << CnDT_string << "\", "; context_param->m_indent.newl(output_param);
                  result = false;
                 }
               }
               context_param->m_indent.indent(output_param);  output_param << "\"" << key_param << "\"" << ":" ; context_param->m_indent.newl(output_param);
               context_param->m_indent.indent(output_param);  output_param << "{" ; context_param->m_indent.newl(output_param);  context_param->m_indent.inc();

               decoration_category(       context_param, output_param, property_param );

               context_param->m_indent.indent(output_param); output_param << "\"value\" : " ;

               return report_type( result );
              }

             static report_type suffix(   contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               if( true == context_param->m_skip )
                {
                 context_param->m_skip = false;
                 return report_type( true );
                }
               context_param->m_skip = false;

               context_param->m_indent.dec();
               context_param->m_indent.newl(output_param);
               context_param->m_indent.indent(output_param);  output_param <<  "}";
               return report_type( true );
              }

             static report_type stasimon( contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               if( true == context_param->m_skip )
                {
                 return report_type( true );
                }
               output_param <<  ",";
               context_param->m_indent.newl( output_param );
               return report_type( true );
              }

             static report_type decoration_category( contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
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

            private:
             static report_type null_value  (      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

             static report_type string(          contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

             static report_type wstring(         contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
              static report_type primitive(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                 output_param<< "{ " << "\""<< note_string << "\" : " << "\"Can not retrieve value.\"" << "}"; //context_param->m_indent.newl(output_param);
                }

                return report_type( true );
               }

            private:
             template < typename enumerator_name >
              static report_type  enumerant      (                           output_type &   output_param, key_type                     const&      key_param, property_qualified_reference_type   property_param )
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

            public:
             template< typename      enum_name>
              static void register_enum( observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< enum_name >();
                auto f = std::bind( &this_type::template enumerant<enum_name>, _1, _2, _3 );
                observe_param.register__any( i, f );
               }

           private:
             template < typename number_name >
              static  report_type complex   ( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                  output_param << "Can not retrieve value.";
                 }

                return report_type( true );
               }

            public:
             template < typename number_name >
              static  void register_complex ( observe_type & observe_param, contextPtr_type &context_param )
              {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::template complex<number_name>, std::ref(observe_param), context_param, _1, _2, _3 );
                observe_param.template register__any< std::complex< number_name> >( f );
               }

            private:
             template < typename first_name, typename second_name >
              static  report_type pair   ( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                typedef std::pair<first_name,second_name> pair_type;
                pair_type const*pointer = nullptr;

                {
                 typedef ::reflection::property::inspect::pure_class<pair_type const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   pointer = &inspect_instance->present();
                   goto print_label;
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<pair_type &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   pointer = &direct_instance->disclose();
                   goto print_label;
                  }
                }

                return report_type( false );
                print_label:
                  context_param->m_indent.newl(output_param); context_param->m_indent.indent(output_param);
                  output_param << "{" ; context_param->m_indent.newl(output_param); context_param->m_indent.inc();
                  observe_param.view( output_param, key_type{ "first" }, ::reflection::content::inspect::pointer<identifier_type,first_name>( &pointer->first ) );
                  output_param << "," ; context_param->m_indent.newl(output_param);
                  observe_param.view( output_param, key_type{ "second" }, ::reflection::content::inspect::pointer<identifier_type,second_name>( &pointer->second ) );
                  context_param->m_indent.dec(); context_param->m_indent.newl(output_param); context_param->m_indent.indent(output_param); output_param << "}" ;
                return true;
               }

            public:
             template < typename first_name, typename second_name >
              static  void register_pair ( observe_type & observe_param, contextPtr_type &context_param )
              {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::template pair<first_name, second_name>, std::ref(observe_param),  context_param,  _1, _2, _3 );
                observe_param.template register__any< std::pair< first_name, second_name > >( f );
               }

            private:
             template < typename first_name, typename second_name >
              static  report_type tuple         ( observe_type const& observe_param, contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                return false;
               }

            public:
             template < typename first_name, typename second_name >
              static  void register_tuple( observe_type & observe_param, contextPtr_type &context_param )
              {
                // TODO
               }

            private:
             template < typename container1_name >
              static  report_type container         ( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
              static  void register_container( observe_type & observe_param, contextPtr_type &context_param )
              {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::template container<container1_name>, std::ref(observe_param), context_param, _1, _2, _3 );
                observe_param.template register__any<container1_name>( f );
               }

            public:
             template < typename map_key_name, typename map_data_name >
              static void register_map( observe_type & observe_param, contextPtr_type &context_param )
               {
                this_type::template register_pair< const map_key_name, map_data_name >( observe_param, context_param );
                this_type::template register_container< std::map<map_key_name, map_data_name> >( observe_param, context_param );
               }

            private:
             static report_type structure( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param,key_type const& key_param, property_qualified_reference_type property_param )
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
                 //context_param->m_indent.indent(output_param);
                 auto const & note_string = context_param->m_key.m_note;
                 auto const & NaS_string = context_param->m_message.m_NaS;
                 output_param<< "{ " << "\"" << note_string << "\"" << ": " << "\""<<  NaS_string << "\"" << "}";
                 //context_param->m_indent.newl(output_param);
                }

               // context_param->m_indent.newl(output_param);
               return report_type( true );
             }

            public:
             template< typename data_name, typename function_name  >
              static void register__any( function_name const& f, observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                return observe_param.template register__any< data_name > ( std::bind( f, context_param, _1, _2, _3 ) );
               }

            public:
             template< typename data_name, typename view_name>
              static void register_class( observe_type & observe_param, contextPtr_type &context_param )
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
