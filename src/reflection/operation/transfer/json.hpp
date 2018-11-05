#ifndef reflection_object_transfer_json
#define reflection_object_transfer_json

// ::reflection::operation::transfer::json_class<output_name,key_name,type_name>

#include "../../type/name/id.hpp"

#include "../../content/category.hpp"
#include "../../content/function/algorithm.hpp"
#include "../../property/structure.hpp"
#include "../../operation/transfer/observe.hpp"





namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename      output_name //!< conect operator << ()
        ,typename         key_name = std::string
        ,typename  identifier_name = std::string
        ,typename      report_name = bool
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct json_struct
        {
         public:
           typedef      output_name        output_type;
           typedef         key_name           key_type;
           typedef  identifier_name    identifier_type;
           typedef      report_name        report_type;

           typedef std::size_t size_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<identifier_type>             category_type;

           typedef typename std::add_const< property_type >::type                          property_qualified_type;
           typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

         public:
           typedef ::reflection::property::structure_class<key_type,container_name>                       structure_type;
           typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>   enumeration_context_type;
           typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
           typedef ::reflection::property::typedefinition::pure_class                        typedefinition_context_type;

         public:
           json_struct( observe_type & observe_param )
            {
             observe_param.control( observe_type::recover_not_category_index  , &json_struct::recover );
             observe_param.control( observe_type::recover_missing_action_index, &json_struct::recover );
           //observe_param.control( observe_type::recover_action_fail_index   , &json_struct::recover );
             observe_param.control( observe_type::recover_null_pointer_index  , &json_struct::null_recover    );

             observe_param.control( observe_type::stage_prologue_index,   &json_struct::prologue );
             observe_param.control( observe_type::stage_stasimon_index ,  &json_struct::stasimon );
             observe_param.control( observe_type::stage_exodus_index ,    &json_struct::exodus   );

             observe_param.insert( identificator_type::template get<  std::string   >(), &json_struct::string   );
             observe_param.insert( identificator_type::template get<  std::wstring  >(), &json_struct::wstring  );

             // TODO observe_param.insert( identificator_type::template get<  std::vector< property_type *>  >(), &json_struct::vector  );
             // TODO observe_param.insert( identificator_type::template get<  std::set<    property_type *>  >(), &json_struct::set     );

             observe_param.insert( identificator_type::template get<  char           >(), &json_struct::primitive<char          >  );
             observe_param.insert( identificator_type::template get<  unsigned char  >(), &json_struct::primitive<unsigned char >  );
             observe_param.insert( identificator_type::template get<  wchar_t        >(), &json_struct::primitive<wchar_t       >  );
             observe_param.insert( identificator_type::template get<  std::wint_t    >(), &json_struct::primitive<std::wint_t   >  );

             observe_param.insert( identificator_type::template get<  std::int8_t    >(), &json_struct::primitive<std::int8_t   >  );
             observe_param.insert( identificator_type::template get<  std::int16_t   >(), &json_struct::primitive<std::int16_t  >  );
             observe_param.insert( identificator_type::template get<  std::int32_t   >(), &json_struct::primitive<std::int32_t  >  );
             observe_param.insert( identificator_type::template get<  std::int64_t   >(), &json_struct::primitive<std::int64_t  >  );

             observe_param.insert( identificator_type::template get<  std::uint8_t   >(), &json_struct::primitive<std::uint8_t  >  );
             observe_param.insert( identificator_type::template get<  std::uint16_t  >(), &json_struct::primitive<std::uint16_t >  );
             observe_param.insert( identificator_type::template get<  std::uint32_t  >(), &json_struct::primitive<std::uint32_t >  );
             observe_param.insert( identificator_type::template get<  std::uint64_t  >(), &json_struct::primitive<std::uint64_t >  );

             observe_param.insert( identificator_type::template get<       float     >(), &json_struct::primitive<     float    >  );
             observe_param.insert( identificator_type::template get<      double     >(), &json_struct::primitive<    double    >  );
             observe_param.insert( identificator_type::template get<  long double    >(), &json_struct::primitive<long double   >  );

             observe_param.insert( identificator_type::template get<  void*          >(), &json_struct::primitive<void*         >  );
             observe_param.insert( identificator_type::template get<  short          >(), &json_struct::primitive<short         >  );
             observe_param.insert( identificator_type::template get<  unsigned short >(), &json_struct::primitive<unsigned short>  );
             observe_param.insert( identificator_type::template get<  int            >(), &json_struct::primitive<int           >  );
             observe_param.insert( identificator_type::template get<  unsigned       >(), &json_struct::primitive<unsigned      >  );
             observe_param.insert( identificator_type::template get<  long           >(), &json_struct::primitive<long          >  );
             observe_param.insert( identificator_type::template get<  long long      >(), &json_struct::primitive<long long     >  );

             observe_param.insert( identificator_type::template get<  nullptr_t      >(), &json_struct::null_value   );

             {
              using namespace std::placeholders;
              auto f = std::bind( &json_struct::enumeration, _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  enumeration_context_type      >(), f );
             }

             {
              using namespace std::placeholders;
              auto f = std::bind( &json_struct::function, _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  algorithm_type      >(), f );
             }

             {
              using namespace std::placeholders;
              auto f = std::bind( &json_struct::typedefinition, _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  typedefinition_context_type      >(), f );
             }

             {
              using namespace std::placeholders;
              auto f = std::bind( &json_struct::structure, _1, std::ref(observe_param), _2, _3 );
              observe_param.insert( identificator_type::template get<  structure_type      >(), f );
              observe_param.control( observe_type::recover_missing_action_index   , f );
             }

            }

         private:
           typedef    std::string       string_type;
           typedef    std::wstring     wstring_type;
           typedef    bool             boolean_type;

           static  report_type   prologue( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param <<  "{ " << std::endl;
             return report_type( true );
            }

           static  report_type   stasimon( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param <<  "," << std::endl;
             return report_type( true );
            }

           static  report_type   exodus ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << std::endl;
             output_param <<  "}" << std::endl;
             return report_type( true );
            }

           static  report_type   recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             return report_type( true );
            }

           static bool null_recover      ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param <<  "null" << std::endl;
             return true;
            }

           static report_type null_value      ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

           static bool string(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
             auto inspect = dynamic_cast< inspect_type const* >( &property_param );
              if( nullptr == inspect )
               {
                return report_type( false );
               }

              output_param << "\"" << key_param << "\"" << ": " << "\""<<  inspect->present() << "\"";
             return report_type( true );
            }

           static bool wstring(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             typedef ::reflection::property::inspect::pure_class<wstring_type const& > inspect_type;
             auto inspect = dynamic_cast< inspect_type const* >( &property_param );
              if( nullptr == inspect )
               {
                 return false;
               }

             // TODO output_param << "\"" << key_param << "\"" << ": " << "\""<<  inspect->present() << "\"";
             return report_type( true );
            }

           template< typename simple_name >
            static report_type primitive(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
             {
              output_param << "\"" << key_param << "\"" << ":" << std::endl ;
              output_param << "  {" << std::endl ;

              {
               category_type const* category = dynamic_cast< category_type const* >( &property_param );
               if( nullptr != category )
                {
                 output_param << "    \"type\" : \"" << category->identifier() << "\", " << std::endl;
                }
               else
                {
                 output_param << "    \"note\" : \"" << "Can not detect type" << "\", " << std::endl;
                }
              }

              bool pass = true;

              if( true == pass )
               {
                typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect_instance )
                 {
                  output_param << "    \"value\" : " << inspect_instance->present();
                  pass = false;
                 }
               }

              if( true == pass )
               {
                typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  output_param << "    \"value\" : " << direct_instance->disclose();
                  pass = false;
                 }
               }

              if( true == pass )
               { 
                output_param << "    \"note\" : " << "\"Can not retrieve value.\"";
               }

              output_param <<  std::endl ;
              output_param << "  }" << "";

              return report_type( true );
             }

           static report_type enumeration( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {

             category_type const* category = dynamic_cast< category_type const* >( &property_param );
             if( nullptr != category )
              {
              }
             else
              {
              }

             enumeration_context_type  const* context = dynamic_cast< enumeration_context_type const* >( &property_param );
             if( nullptr == context )
              {
               return report_type( false );
              }

             output_param << "\"" << key_param    << "\": " << std::endl;
             output_param <<  "  [ " << std::endl;

             for( std::size_t index=0; index < context->container().size(); ++index )
              {
               output_param << "    { ";
               output_param << "\"ordinal\": " << std::setw(3) << index << ", ";
               output_param << "\"value\": "   << std::setw(4) << context->container()[index].value() << ", ";
               output_param << "\"name\":\""   << context->container()[index].name() << "\" ";
               output_param << "    }";
               if( index+1< context->container().size()) output_param << ",";

               output_param << std::endl;
              }
             output_param << "  ] ";

             return report_type( true );
            }

           static report_type function ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             category_type const* category = dynamic_cast< category_type const* >( &property_param );

             if( nullptr != category )
              {
              }
             else
              {
              }

             algorithm_type  const* context = dynamic_cast< algorithm_type const* >( &property_param );
             if( nullptr == context )
              {
               return report_type( false );
              }

             output_param << "\"" << key_param << "\" :" << std::endl;
             output_param << "  { " << std::endl;

             output_param << "    \"type\": \"" << category->identifier() <<  "\", " << std::endl;

             output_param << "    \"parameters\": " << std::endl;
             output_param << "    [ " << std::endl;
             for( std::size_t index=0; index < context->signature().size(); ++index )
              {
               if( context->signature()[index] == identificator_type::NAT() )
                {
                 continue;
                }
               output_param << "        { ";
               output_param << "\"ordinal\": " << std::setw(3) << index << ", ";
               output_param << "\"type\": "   << "\""<< context->signature()[index] << "\" ";

             //output_param << "\"name\":\""   << context->container()[index].name() << "\" ";
               output_param << "    }";
               output_param << std::endl;
             }
             output_param << "    ] "<< std::endl;

             output_param << "  } " << std::endl;

             return report_type( true );
            }

           static report_type typedefinition ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             category_type const* category = dynamic_cast< category_type const* >( &property_param );
             if( nullptr != category )
              {
              }
             else
              {
              }

             typedefinition_context_type  const* context = dynamic_cast< typedefinition_context_type const* >( &property_param );
             if( nullptr == context )
              {
               return report_type( false );
              }

             output_param << "\"" << key_param << "\" :" << std::endl;
             output_param << "  { " << std::endl;

             output_param << "    \"type\": " << category->identifier() << ", " << std::endl;
             output_param << "    \"original\": \"" << context->name()<< "\""  << std::endl;
             output_param << "  } " << std::endl;

             return report_type( true );
            }

           static report_type structure ( output_type & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << "\"" << key_param << "\"" << ": ";

             {
              category_type const* category = dynamic_cast< category_type const* >( &property_param );
              if( nullptr != category )
               {
               }
              else
               {
               }
             }

             bool pass = true;

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

             output_param << std::endl;
             return report_type( true );
           }

        };

     }
   }
 }

#endif
