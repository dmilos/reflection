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
                size_type m_ident=0;
                string_type m_element="e";
                string_type m_item="i";
                string_type m_name="n";
                string_type m_note="m";

                void inc(){ ++m_ident; }
                void dec(){ --m_ident; }
                size_type const& get()const{ return m_ident; }
                void newl( output_type & output_param ){ output_param << std::endl; for( size_type i=0; i< this->get(); ++i ) output_param <<  "  "; }
               }context_type;

             typedef std::shared_ptr< context_struct > contextPtr_type;

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

           public:

           public:
             explicit serialize_struct( observe_type & observe_param, contextPtr_type context = serialize_struct::context() )
              {
               using namespace std::placeholders;

               observe_param.control( observe_type::recover_not_category_index  , &this_type::recover );
             //observe_param.control( observe_type::recover_missing_action_index, &this_type::recover );
               observe_param.control( observe_type::recover_action_fail_index   , &this_type::recover );

               observe_param.control( observe_type::stage_introductum_index,   std::bind( &this_type::introductum, context, _1, _2, _3 ) );

               observe_param.control( observe_type::stage_prefix_index,         std::bind( &this_type::prefix, context, _1, _2, _3 )      );
               observe_param.control( observe_type::stage_suffix_index,         std::bind( &this_type::suffix, context, _1, _2, _3 )     );

               observe_param.control( observe_type::stage_conclusio_index ,    std::bind( &this_type::conclusio, context, _1, _2, _3 )   );

               observe_param.insert( identificator_type::template get< std::string    >(), &this_type::primitive<std::string   >  );
               observe_param.insert( identificator_type::template get<  std::wstring  >(), &this_type::wstring  );

               observe_param.insert( identificator_type::template get<  char           >(), &this_type::primitive<char          >  );
               observe_param.insert( identificator_type::template get<  unsigned char  >(), &this_type::primitive<unsigned char >  );
               observe_param.insert( identificator_type::template get<  wchar_t        >(), &this_type::primitive<wchar_t       >  );
               observe_param.insert( identificator_type::template get<  std::wint_t    >(), &this_type::primitive<std::wint_t   >  );

               observe_param.insert( identificator_type::template get<  std::int8_t    >(), &this_type::primitive<std::int8_t   >  );
               observe_param.insert( identificator_type::template get<  std::int16_t   >(), &this_type::primitive<std::int16_t  >  );
               observe_param.insert( identificator_type::template get<  std::int32_t   >(), &this_type::primitive<std::int32_t  >  );
               observe_param.insert( identificator_type::template get<  std::int64_t   >(), &this_type::primitive<std::int64_t  >  );

               observe_param.insert( identificator_type::template get<  std::uint8_t   >(), &this_type::primitive<std::uint8_t  >  );
               observe_param.insert( identificator_type::template get<  std::uint16_t  >(), &this_type::primitive<std::uint16_t >  );
               observe_param.insert( identificator_type::template get<  std::uint32_t  >(), &this_type::primitive<std::uint32_t >  );
               observe_param.insert( identificator_type::template get<  std::uint64_t  >(), &this_type::primitive<std::uint64_t >  );

               observe_param.insert( identificator_type::template get<       float     >(), &this_type::primitive<     float    >  );
               observe_param.insert( identificator_type::template get<      double     >(), &this_type::primitive<    double    >  );
               observe_param.insert( identificator_type::template get<  long double    >(), &this_type::primitive<long double   >  );

               observe_param.insert( identificator_type::template get<  void*          >(), &this_type::primitive<void*         >  );
               observe_param.insert( identificator_type::template get<  short          >(), &this_type::primitive<short         >  );
               observe_param.insert( identificator_type::template get<  unsigned short >(), &this_type::primitive<unsigned short>  );
               observe_param.insert( identificator_type::template get<  int            >(), &this_type::primitive<int           >  );
               observe_param.insert( identificator_type::template get<  unsigned       >(), &this_type::primitive<unsigned      >  );
               observe_param.insert( identificator_type::template get<  long           >(), &this_type::primitive<long          >  );
               observe_param.insert( identificator_type::template get<  long long      >(), &this_type::primitive<long long     >  );

               observe_param.insert( identificator_type::template get<  nullptr_t      >(), &this_type::null_value   );
              }

           private:
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //output_param << "<" << context->m_note << " message=\"Continue like nothing happen.\" /> ";
                 output_param << "<" << "note" << " message=\"Continue like nothing happen.\" /> ";

               return report_type( true );
              }

             static report_type introductum( contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context->newl( output_param );
               output_param <<  "<"<< context->m_element << ">" ;
               context->inc();
               return report_type( true );
              }

             static report_type conclusio (  contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context->dec();
               output_param <<  "</"<< context->m_element <<">" ;
               context->newl( output_param );
               return report_type( true );
              }

             static report_type prefix(      contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context->newl( output_param );
               output_param << "<" << context-> m_item << " ";
               context->inc();

               if( key_type{} != key_param ) output_param << context-> m_name << "=\"" << key_param << "\" ";

               report_type result = true;

               output_param << ">";
               return report_type( result );
              }

             static report_type suffix(      contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context->dec(); //context->newl( output_param );
               output_param << "</"<< context->m_item << ">";
               return report_type( true );
              }

             static report_type null_value(                                  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null )
                {
                 return report_type( false );
                }

               output_param << "<value content=\"null\" />";
               return report_type( true );
              }

             static report_type wstring(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
              static report_type primitive(                                  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                  output_param << "   <note message=\"Can not retrieve value\" />";
                 }

                return report_type( true );
               }

            public:
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

             template < typename data_name >
              static  report_type list           ( contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                return report_type( true );
               }

             template < typename key_type, typename data_name >
              static  report_type map            ( contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                return report_type( true );
               }

             template < typename key_type >
              static  report_type set            ( contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                return report_type( true );
               }

             template < typename data_name >
              static  report_type vector         ( contextPtr_type &context, observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                typedef std::vector<data_name> vector_type;

                vector_type const*pointer = nullptr;

                {
                 typedef ::reflection::property::inspect::pure_class<vector_type const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   pointer = &inspect_instance->present();
                   goto print_label;
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<vector_type &>         direct_type;
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
                   observe_param.view( output_param, key_type{}, ::reflection::content::inspect::pointer<identifier_type,data_name>( &item ) );
                  }
                 return report_type( true );
               }

             static  report_type  structure( observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param  )
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
                 output_param << "<note message=\"Not a structure\" /> ";
                }

               return report_type( true );
              }

         };

       }
     }
   }
 }

#endif
