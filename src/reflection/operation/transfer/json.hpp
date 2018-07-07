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
         typename output_name
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

           typedef typename std::add_const< ::reflection::property::pure_class>::type                property_qualified_type;

           typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, type_type, report_type, std::add_const, container_name > observe_type;

           json_struct( observe_type & observe_param )
            {
             observe_param.protocol().emplace( typeid( std::string    ).name(), std::bind( &json_struct::basic<std::string>,  std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );
             observe_param.protocol().emplace( typeid(      double    ).name(), std::bind( &json_struct::basic<double>,       std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );
             observe_param.protocol().emplace( typeid(       float    ).name(), std::bind( &json_struct::basic<float>,        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );
             observe_param.protocol().emplace( typeid(         int    ).name(), std::bind( &json_struct::basic<int>,          std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );
             observe_param.protocol().emplace( typeid(    unsigned    ).name(), std::bind( &json_struct::basic<unsigned>,     std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );
             observe_param.protocol().emplace( typeid(       bool     ).name(), std::bind( &json_struct::basic<bool>,         std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );
             observe_param.protocol().emplace( typeid(  nullptr_t     ).name(), std::bind( &json_struct::null,                std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );
             observe_param.protocol().emplace( typeid( structure_type ).name(), std::bind( &json_struct::structure,           std::placeholders::_1, std::ref(observe_param), std::placeholders::_2, std::placeholders::_3 ) );
            }

         private:
           typedef    std::string       string_type;
           typedef    bool             boolean_type;

           template
            <
             typename number_name
            >
            static bool basic (  output_type & output_param, key_type const& key_param, property_qualified_type & property_param )
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

           static bool structure( output_type & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_type & property_param )
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

           static bool null     ( output_type & output_param, key_type const& key_param, property_qualified_type & property_param )
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
