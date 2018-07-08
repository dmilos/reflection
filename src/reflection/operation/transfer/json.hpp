#ifndef reflection_object_transfer_json
#define reflection_object_transfer_json

// ::reflection::operation::transfer::json_class<output_name,key_name,type_name>

#include "../../content/category.hpp"
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
         typename output_name   //!< conect operator << ()
        ,typename      key_name = std::string
        ,typename     type_name = std::string
        ,typename   report_name = bool
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct json_struct
        {
         public:
           typedef  output_name     output_type;
           typedef     key_name        key_type;
           typedef    type_name       type_type;
           typedef    report_name   report_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<type_type>             category_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef typename std::add_const< property_type >::type                          property_qualified_type;
           typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

           typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, type_type, report_type, std::add_const, container_name > observe_type;

           json_struct( observe_type & observe_param )
            {
             observe_param.protocol().emplace( typeid(  std::string    ).name(), &json_struct::basic<std::string   >  );
             // TODO observe_param.protocol().emplace( typeid(  std::wstring   ).name(), &json_struct::basic<std::wstring  >  );

             observe_param.protocol().emplace( typeid(  char           ).name(), &json_struct::basic<char          >  );
             observe_param.protocol().emplace( typeid(  unsigned char  ).name(), &json_struct::basic<unsigned char >  );
             observe_param.protocol().emplace( typeid(  wchar_t        ).name(), &json_struct::basic<wchar_t  >  );
             observe_param.protocol().emplace( typeid(  std::wint_t    ).name(), &json_struct::basic<std::wint_t   >  );

             observe_param.protocol().emplace( typeid(  std::int8_t    ).name(), &json_struct::basic<std::int8_t   >  );
             observe_param.protocol().emplace( typeid(  std::int16_t   ).name(), &json_struct::basic<std::int16_t  >  );
             observe_param.protocol().emplace( typeid(  std::int32_t   ).name(), &json_struct::basic<std::int32_t  >  );
             observe_param.protocol().emplace( typeid(  std::int64_t   ).name(), &json_struct::basic<std::int64_t  >  );

             observe_param.protocol().emplace( typeid(  std::uint8_t   ).name(), &json_struct::basic<std::uint8_t  >  );
             observe_param.protocol().emplace( typeid(  std::uint16_t  ).name(), &json_struct::basic<std::uint16_t >  );
             observe_param.protocol().emplace( typeid(  std::uint32_t  ).name(), &json_struct::basic<std::uint32_t >  );
             observe_param.protocol().emplace( typeid(  std::uint64_t  ).name(), &json_struct::basic<std::uint64_t >  );

             observe_param.protocol().emplace( typeid(       float     ).name(), &json_struct::basic<     float    >  );
             observe_param.protocol().emplace( typeid(      double     ).name(), &json_struct::basic<    double    >  );
             observe_param.protocol().emplace( typeid(  long double    ).name(), &json_struct::basic<long double   >  );

             observe_param.protocol().emplace( typeid(  void*          ).name(), &json_struct::basic<void*         >  );
             observe_param.protocol().emplace( typeid(  short          ).name(), &json_struct::basic<short         >  );
             observe_param.protocol().emplace( typeid(  unsigned short ).name(), &json_struct::basic<unsigned short>  );
             observe_param.protocol().emplace( typeid(  int            ).name(), &json_struct::basic<int           >  );
             observe_param.protocol().emplace( typeid(  unsigned       ).name(), &json_struct::basic<unsigned      >  );
             observe_param.protocol().emplace( typeid(  long           ).name(), &json_struct::basic<long          >  );
             observe_param.protocol().emplace( typeid(  long long      ).name(), &json_struct::basic<long long     >  );

             // TODO observe_param.protocol().emplace( typeid(  nullptr_t     ).name(), &json_struct::basic<nullptr_t     >   );
            }

         private:
           typedef    std::string       string_type;
           typedef    bool             boolean_type;

           template
            <
             typename number_name
            >
            static bool basic (  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
             {
              typedef ::reflection::property::inspect::pure_class<number_name const& > inspect_type;
              auto inspect = dynamic_cast< inspect_type const* >( &property_param );
               if( nullptr == inspect )
                {
                  return false;
                }

              output_param <<  key_param << ": " <<  inspect->present() << std::endl;
              return true;
             }

           static bool structure( output_type & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << "{  ";
             output_param << key_param    << ": ";

             if( false == ::reflection::property::inspect::check < structure_type const& >( property_param ) )
              {
               return false;
              }

             observe_param.view( output_param, ::reflection::property::inspect::present< structure_type const& >( property_param )  );

             output_param << "}";
             output_param << std::endl;
             return true;
           }

           static bool null     ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             typedef ::reflection::property::null_class null_type;
             auto null = dynamic_cast< null_type const* >( &property_param );
             if( nullptr == null )
              {
               return false;
              }

             output_param <<  key_param << ": " <<  "null" << std::endl;
             return true;
            }

        };



     }
   }
 }

#endif
