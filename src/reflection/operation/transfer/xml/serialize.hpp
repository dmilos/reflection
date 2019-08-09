#ifndef reflection_operation_transfer_xml_serialize
#define reflection_operation_transfer_xml_serialize

// ::reflection::operation::transfer::xml_class<output_name,key_name,type_name>

#include "../../../content/inspect/inspect.hpp"
#include "../../../content/category.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/transfer/observe.hpp"





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
         struct serialize_struct
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
                 struct tag_struct
                  {
                   bool m_show;
                   string_type m_name;
                  };

                 struct attribute_struct
                  {
                   bool m_show;
                   string_type m_name;
                   string_type m_content;
                  };

                 tag_struct m_element ={ true, "e"  };
                 tag_struct m_item    ={ true, "i"  };
                 tag_struct m_name    ={ true, "n"  };
                 tag_struct m_remark  ={ true, "r"  };
                 tag_struct m_intro   ={ true, "xml"};

                 attribute_struct m_type           ={ true, "t", "" };
                 attribute_struct m_messageNULL    ={ true, "N", "nullptr" };
                 attribute_struct m_messageNotM    ={ true, "N", "Not in the menu" };
                 attribute_struct m_messageRecover ={ true, "N", "Continue like nothing happen." };
                 attribute_struct m_messageCNRV    ={ true, "N", "Can not retrieve value." };
                 attribute_struct m_NULL           ={ true, "N", "" };
                 attribute_struct m_NaS            ={ true, "N", "Not a structure" };

                private:
                  friend struct  reflection::operation::transfer::xml::serialize_struct<output_name,key_name,identifier_name, report_name, container_name>;
                  size_type   m_ident=0;
                std::string m_tabulator="    ";
                  void inc(){ ++m_ident; }
                  void dec(){--m_ident; }
                  size_type const& get()const{ return m_ident; }
                  void indent( output_type & output_param ){ for( size_type i=0; i< this->get(); ++i ) output_param << m_tabulator; }
                  void newl( output_type & output_param ){ output_param << std::endl; for( size_type i=0; i< this->get(); ++i ) output_param <<  "  "; }
               }context_type;

             typedef std::shared_ptr< context_type > contextPtr_type;

           public:
             static contextPtr_type context(){ return std::make_shared<context_struct>(); }

           public:
             typedef ::reflection::operation::transfer::xml::serialize_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

             typedef typename observe_type::protocol_type  protocol_type;

           public:

           public:
             explicit serialize_struct( observe_type & observe_param, contextPtr_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               observe_param.control( observe_type::recover_type_acquisition_index  , std::bind( &this_type::recover, context_param, _1, _2, _3 ) );
             //observe_param.control( observe_type::recover_action_acquisition_index, std::bind( &this_type::recover, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::recover_action_fail_index,        std::bind( &this_type::recover, context_param, _1, _2, _3 ) );

               observe_param.control( observe_type::stage_introductum_index, std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_exodus_index ,     std::bind( &this_type::exodus,      context_param, _1, _2, _3 )   );

               observe_param.control( observe_type::stage_prolog_index,      std::bind( &this_type::prolog, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_epilog_index ,     std::bind( &this_type::epilog, context_param, _1, _2, _3 )   );
                                                                             
               observe_param.control( observe_type::stage_prefix_index,      std::bind( &this_type::prefix, std::ref( observe_param ), context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_suffix_index,      std::bind( &this_type::suffix, std::ref( observe_param ), context_param, _1, _2, _3 ) );

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
              }

           private:
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover(     contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               tag<true>( output_param, context_param->m_remark, context_param->m_messageRecover );
               return report_type( true );
              }

             static report_type introductum( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->newl( output_param );
               tag<false>( output_param, context_param->m_intro );
               context_param->inc();
               return report_type( true );
              }

             static report_type exodus (  contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec();
               output_param <<  "</"<< context_param->m_intro.m_name << ">" ;
               context_param->newl( output_param );
               return report_type( true );
              }

             static report_type prolog( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->newl( output_param );
               tag<false>( output_param, context_param->m_element );
               context_param->inc();
               return report_type( true );
              }

             static report_type epilog (  contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec();
               output_param <<  "</"<< context_param->m_element.m_name << ">" ;
               //context_param->newl( output_param );
               return report_type( true );
              }

             static report_type prefix(  observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //context_param->newl( output_param );
               output_param << "<" << context_param-> m_item.m_name << " ";
               if( key_type{} != key_param ) output_param << context_param-> m_name.m_name << "=\"" << key_param << "\" ";

               {
                category_type const* category_item = dynamic_cast< category_type const* >( &property_param );
                if( nullptr == category_item )
                 {
                  attribute( output_param, context_param-> m_messageNULL );
                  output_param << " >";
                  context_param->inc();
                  return report_type( false );
                 }

                if(  true == context_param->m_type.m_show )
                 {
                  output_param << context_param-> m_type.m_name << "=\"" << category_item->identifier() << "\" ";
                 }

                if( false == protocol_type::exists( observe_param.menu(), category_item->identifier() ) )
                 {
                  attribute( output_param, context_param-> m_messageNotM );
                  output_param << " >";
                  context_param->inc();
                  return report_type( false );
                 }
               }

               output_param << " >";
               context_param->inc();

               return report_type( true );
              }

             static report_type suffix(  observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec(); 
               output_param << "</"<< context_param->m_item.m_name << ">";
               context_param->newl( output_param );
               return report_type( true );
              }

             static void attribute( output_type & output_param, typename context_type::attribute_struct const& attribute_param )
              {
               if( false == attribute_param.m_show )
                {
                 return;
                }
               output_param << attribute_param.m_name
                            << "=\"" << attribute_param.m_content << "\"";
              }

             template< bool single_bool >
              static void tag( output_type & output_param, typename context_struct::tag_struct const& tag_param )
               {
                output_param << "<" << tag_param.m_name <<" ";
                if( true == single_bool ) output_param <<"/";
                output_param << ">";
               }

             template< bool single_bool >
              static void tag( output_type & output_param, typename context_struct::tag_struct const& tag_param, typename context_struct::attribute_struct const& a1_param )
               {
                output_param << "<" << tag_param.m_name <<" ";
                attribute( output_param, a1_param );
                if( true == single_bool ) output_param <<"/";
                output_param << ">";
               }

             static report_type null_value(   contextPtr_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null ) 
                {
                 tag<true>( output_param, context_param->m_remark, context_param->m_messageCNRV ); 
                 return report_type( false );
                }

               output_param << "<value content=\"null\" />"; // !< TODO <-- tag<true>( output_param, context_param->m_null, context_param->m_messageCNRV ); 
               
               return report_type( true );
              }

             static report_type wstring(     contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
              static report_type primitive(  contextPtr_type & context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                  tag<true>( output_param, context_param->m_remark, context_param->m_messageCNRV );
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

             template < typename number_name >
              static  report_type complex ( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                  tag<true>( output_param, context_param->m_remark, context_param->m_messageCNRV );
                 }

                return report_type( true );
              }

             template < typename first_name, typename second_name >
              static  report_type pair   ( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                // auto f = ::reflection::content::inspect::pointer( property_param.first );
                // auto s = ::reflection::content::inspect::pointer( property_param.secon );
                //observe_param.view( output_param, f );
                //observe_param.view( output_param, s );
                return false;
               }

             template < typename first_name, typename second_name >
              static  report_type tuple         ( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                return false;
               }

             static  report_type  structureX(     observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                 tag( output_param, context_param->m_note, context_param->m_NaS );
                }

               return report_type( true );
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

             template < typename number_name >
              static  void register_complex ( observe_type & observe_param, contextPtr_type &context_param )
              {
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< std::complex< number_name> >();
                auto f = std::bind( &this_type::template complex<number_name>,  std::ref(observe_param), context_param,_1, _2, _3 );
                observe_param.register__any( i, f );
              }

             template < typename first_name, typename second_name >
              static  void register_pair ( observe_type & observe_param, contextPtr_type &context_param )
              {
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< std::pair< first_name, second_name > >();
                auto f = std::bind( &this_type::template pair<first_name, second_name>,  std::ref(observe_param), context_param, _1, _2, _3 );
                observe_param.register__any( i, f );
              }

             template < typename first_name, typename second_name >
              static  void register_tuple( observe_type & observe_param, contextPtr_type &context_param )
              {
                // TODO
               }

             template < typename container_value_name >
              static  report_type container         ( observe_type const& observe_param, contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

                 for( auto const&  item: *pointer )
                  {
                   output_param << "<v>";
                   observe_param.view( output_param, key_type{}, ::reflection::content::inspect::pointer<identifier_type,typename container_type::value_type>( &item ) );
                   output_param << "</v>";
                  }
                 return report_type( true );
               }

             template < typename container_value_name >
              static  void register_container( observe_type & observe_param, contextPtr_type &context_param )
              {
                typedef container_value_name container_type;
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< container_type >();
                auto f = std::bind( &this_type::template container<container_type>, std::ref(observe_param), context_param, _1, _2, _3 );
                observe_param.register__any( i , f );
               }

             template < typename map_key_name, typename map_data_name >
              static  void register_map( observe_type & observe_param, contextPtr_type &context_param )
              {
               this_type::template register_pair< map_key_name, map_data_name >( observe_param, context_param );
               this_type::template register_container< std::map<map_key_name, map_data_name> >( observe_param, context_param );;
              }

             template< typename data_name, typename view_name>
              static void register_class( observe_type & observe_param, contextPtr_type &context_param )
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
