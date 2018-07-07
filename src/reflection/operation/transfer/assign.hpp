#ifndef reflection_object_assign
#define reflection_object_assign

// ::reflection::operation::transfer::assign<key_name>

#include "../../content/category.hpp"
#include "../../property/structure.hpp"
#include "../../operation/transfer/observe.hpp"

#include "../property/assign.hpp"



namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename      key_name = std::string
        ,typename     type_name = std::string
        ,typename   report_name = bool
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct assign_struct
        {
         public:
           typedef     key_name        key_type;
           typedef    type_name       type_type;
           typedef    report_name   report_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<type_type>             category_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;
           
           typedef  structure_type     output_type;

           typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, type_type, report_type, std::add_const, container_name > observe_type;

           enum error_enum
            {
             true_index                = (true),
             left_not_found_index      = true_index + 1,
             left_not_property_index   = true_index + 2,
             assign_fail_index         = true_index + 3,
            };

         public:
           assign_struct( observe_type & observe_param )
            {
             //observe_param.protocol().emplace( typeid(  std::string    ).name(), &assign_struct::process<std::string   >  );
            /* observe_param.protocol().emplace( typeid(  std::wstring   ).name(), &assign_struct::process<std::wstring  >  );

             observe_param.protocol().emplace( typeid(  char           ).name(), &assign_struct::process<char          >  );
             observe_param.protocol().emplace( typeid(  unsigned char  ).name(), &assign_struct::process<unsigned char >  );
             observe_param.protocol().emplace( typeid(  wchar_t        ).name(), &assign_struct::process<wchar_t  >  );
             observe_param.protocol().emplace( typeid(  std::wint_t    ).name(), &assign_struct::process<std::wint_t   >  );

             observe_param.protocol().emplace( typeid(  std::int8_t    ).name(), &assign_struct::process<std::int8_t   >  );
             observe_param.protocol().emplace( typeid(  std::int16_t   ).name(), &assign_struct::process<std::int16_t  >  );
             observe_param.protocol().emplace( typeid(  std::int32_t   ).name(), &assign_struct::process<std::int32_t  >  );
             observe_param.protocol().emplace( typeid(  std::int64_t   ).name(), &assign_struct::process<std::int64_t  >  );

             observe_param.protocol().emplace( typeid(  std::uint8_t   ).name(), &assign_struct::process<std::uint8_t  >  );
             observe_param.protocol().emplace( typeid(  std::uint16_t  ).name(), &assign_struct::process<std::uint16_t >  );
             observe_param.protocol().emplace( typeid(  std::uint32_t  ).name(), &assign_struct::process<std::uint32_t >  );
             observe_param.protocol().emplace( typeid(  std::uint64_t  ).name(), &assign_struct::process<std::uint64_t >  );

             observe_param.protocol().emplace( typeid(       float     ).name(), &assign_struct::process<     float    >  );
             observe_param.protocol().emplace( typeid(      double     ).name(), &assign_struct::process<    double    >  );
             observe_param.protocol().emplace( typeid(  long double    ).name(), &assign_struct::process<long double   >  );

             observe_param.protocol().emplace( typeid(  void*          ).name(), &assign_struct::process<void*         >  );
             observe_param.protocol().emplace( typeid(  short          ).name(), &assign_struct::process<short         >  );
             observe_param.protocol().emplace( typeid(  unsigned short ).name(), &assign_struct::process<unsigned short>  );
             observe_param.protocol().emplace( typeid(  int            ).name(), &assign_struct::process<int           >  );
             observe_param.protocol().emplace( typeid(  unsigned       ).name(), &assign_struct::process<unsigned      >  );
             observe_param.protocol().emplace( typeid(  long           ).name(), &assign_struct::process<long          >  );
             observe_param.protocol().emplace( typeid(  long long      ).name(), &assign_struct::process<long long     >  );

             observe_param.protocol().emplace( typeid(  nullptr_t     ).name(), &assign_struct::process<nullptr_t     >               );
             */// TODO observe_param.protocol().emplace( typeid( structure_type ).name(), std::bind( &assign_struct::process,               std::placeholders::_1, std::ref(observe_param), std::placeholders::_2, std::placeholders::_3 ) );
            }

         public:
           template
            <
              typename       type_name
             ,typename      image_name = typename std::add_lvalue_reference< typename std::add_const<type_name>::type >::type
             ,typename   original_name = typename std::add_lvalue_reference< type_name >::type
             ,typename      model_name = typename std::add_lvalue_reference< typename std::add_const<type_name>::type >::type
            >
           static error_enum process( structure_type & output_param, key_type const& key_param, property_type const& property_param )
            {
             auto iterator = output_param.container().find( key_param );
             if( output_param.container().end() == iterator )
              {
               return left_not_found_index;
              }
             auto right = iterator->second;

             property_type *  left = dynamic_cast< property_type * >( iterator->second.get() );
             if( nullptr == left )
              {
               return left_not_property_index;
              }

             if( false == ::reflection::property::assign<type_name, error_enum, image_name, original_name, model_name >( *left, *right ) )
              {
               return assign_fail_index;
              }

             return true_index;
            }

        };

     }
   }
 }

#endif
