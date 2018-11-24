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
             typedef std::size_t size_type;
             typedef struct context_struct
              {
                size_type m_ident=0;
                bool   m_skip=false;
                void inc(){ ++m_ident; }
                void dec(){ --m_ident; }
               }context_type;

             typedef std::shared_ptr< context_type > contextPtr_type;

          public:
            static contextPtr_type context(){ return std::make_shared<context_struct>(); }

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

               observe_param.control( observe_type::recover_not_category_index  , &this_type::recover );
               observe_param.control( observe_type::recover_missing_action_index, &this_type::recover );
             //observe_param.control( observe_type::recover_action_fail_index   , &this_type::recover );
               observe_param.control( observe_type::recover_null_pointer_index  , &this_type::null_recover    );

               observe_param.control( observe_type::stage_introductum_index, std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_stasimon_index ,   std::bind( &this_type::stasimon,    context_param, _1, _2, _3 ) );;
               observe_param.control( observe_type::stage_prefix_index,      std::bind( &this_type::prefix,      context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_suffix_index,      std::bind( &this_type::suffix,      context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_conclusio_index ,  std::bind( &this_type::conclusio,   context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  std::string   >(), &this_type::string   );
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

               {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::structure, _1, std::ref(observe_param), _2, _3 );
                auto i = identificator_type::template get<  structure_type      >();
                observe_param.insert( i, f );
               }

              }

           private:
             typedef    std::string       string_type;
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               return report_type( true );
              }

             static report_type introductum( contextPtr_type context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->inc();
               output_param <<  "{" << std::endl;
               return report_type( true );
              }

             static report_type conclusio  ( contextPtr_type context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << std::endl;
               output_param <<  "}" << std::endl;
               context_param->dec();
               return report_type( true );
              }

             static report_type prefix(   contextPtr_type context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                  output_param << " //! Can not detect type ";
                  result = false;
                 }
               }

               output_param << "\"" << key_param << "\"" << ":" << std::endl ;
               output_param << "  {" << std::endl ;

               decoration_category(       context_param, output_param, property_param );

               output_param << "    \"value\"  : " ;

               return report_type( result );
              }

             static report_type suffix(   contextPtr_type context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               if( true == context_param->m_skip )
                {
                 context_param->m_skip = false;
                 return report_type( true );
                }
               context_param->m_skip = false;
               output_param << std::endl;
               output_param <<  "  }";
               //output_param << std::endl;
               return report_type( true );
              }

             static report_type stasimon( contextPtr_type context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               if( true == context_param->m_skip )
                {
                 return report_type( true );
                }
               output_param <<  "," << std::endl;
               return report_type( true );
              }

             static report_type decoration_category( contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
               {
                category_type const* category = dynamic_cast< category_type const* >( &property_param );
                if( nullptr != category )
                 {
                  output_param << "    \"type\"  : \"" << category->identifier() << "\", " << std::endl;
                  return report_type( true );
                 }
                else
                 {
                  output_param << "    \"note\"  : \"" << "Can not detect type" << "\", " << std::endl;
                  return report_type( true );
                 }
                return report_type( true );
               }

             static report_type null_recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  "null" << std::endl;
               return true;
              }

             static report_type null_value  ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null )
                {
                 return report_type( false );
                }

               output_param << "\"" << key_param << "\"" << ": " <<  "null" << std::endl;
               return report_type( true );
              }

             static report_type string(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
               output_param << "    \"" << "note" << "\"" << ": " << "\""<<  "Can not retrieve the value." << "\"";
               return report_type( true );
              }

             static report_type wstring(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  // TODO output_param << "\""<<  inspect->present() << "\"";
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
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
              static report_type primitive(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                {
                 typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   output_param << inspect_instance->present();
                   return report_type( true );
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   output_param << direct_instance->disclose();
                   return report_type( true );
                  }
                }

                {
                 output_param << "    \"note\" : " << "\"Can not retrieve value.\"";
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

             template< typename      enum_name>
              static void register_enum( observe_type & observe_param, contextPtr_type &context_param )
               {
                using namespace std::placeholders;
                auto i = this_type::identificator_type::template get< enum_name >();
                auto f = std::bind( &this_type::template enumerant<enum_name>, _1, _2, _3 );
                observe_param.register__any( i, f );
               }

             template < typename number_name >
              static  report_type complex   ( observe_type const& observe_param, contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                return false;
               }

             template < typename number_name >
              static  void register_complex ( observe_type & observe_param, contextPtr_type &context_param )
              {
                // TODO
               }

             template < typename first_name, typename second_name >
              static  report_type pair   ( observe_type const& observe_param, contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                return false;
               }

             template < typename first_name, typename second_name >
              static  void register_pair ( observe_type & observe_param, contextPtr_type &context_param )
              {
                // TODO
               }

             template < typename first_name, typename second_name >
              static  report_type tuple         ( observe_type const& observe_param, contextPtr_type &context, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                // TODO
                return false;
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
              static void register_map( observe_type & observe_param, contextPtr_type &context_param )
               {
               this_type::template register_pair< map_key_name, map_data_name >( observe_param, context_param );
               this_type::template register_container< std::map<map_key_name, map_data_name> >( observe_param, context_param );;
               }

             static report_type structure ( output_type & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                 // TODO(or not)output_param << "<note message=\"Not a structure\" /> ";
                }

               //output_param << std::endl;
               return report_type( true );
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





