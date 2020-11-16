#ifndef reflection_operation_assign
#define reflection_operation_assign

// ::reflection::operation::transfer::assign<key_name>

#include "../../content/category.hpp"
#include "../../property/structure.hpp"
#include "../../operation/encode/observe.hpp"

#include "../../property/assign.hpp"



namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename      key_name = std::string
        ,typename     identifier_name = std::string
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct assign_struct
        {
         public:
           typedef     key_name        key_type;
           typedef    identifier_name       identifier_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::ornament::category_class<identifier_type>            category_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           typedef  structure_type                output_type;
         public:
           typedef ::reflection::operation::transfer::assign_struct<key_name,identifier_name, container_name> this_type;

           enum error_enum
            {
             false_index               = (false),
             true_index                = (true),
             left_not_found_index      = true_index + 1,
             left_not_property_index   = true_index + 2,
             left_not_structure_index  = true_index + 3,
             assign_fail_index         = true_index + 4,
            };

           typedef  ::reflection::operation::encode::observe_class< output_type, key_type, identifier_type, error_enum, std::add_const, container_name > observe_type;

         public:
           explicit assign_struct( observe_type & observe_param )
            {
             using namespace std::placeholders;

             observe_param.insert( identificator_type::template get<  bool          >(), &this_type::process< bool          >  );

             observe_param.insert( identificator_type::template get< char           >(), &this_type::process< char          >  );
             observe_param.insert( identificator_type::template get< unsigned char  >(), &this_type::process< unsigned char >  );
             observe_param.insert( identificator_type::template get< wchar_t        >(), &this_type::process< wchar_t       >  );
             observe_param.insert( identificator_type::template get< std::wint_t    >(), &this_type::process< std::wint_t   >  );
             observe_param.insert( identificator_type::template get< char16_t       >(), &this_type::process< char16_t      >  );
             observe_param.insert( identificator_type::template get< char32_t       >(), &this_type::process< char32_t      >  );

             observe_param.insert( identificator_type::template get< std::int8_t    >(), &this_type::process< std::int8_t   >  );
             observe_param.insert( identificator_type::template get< std::int16_t   >(), &this_type::process< std::int16_t  >  );
             observe_param.insert( identificator_type::template get< std::int32_t   >(), &this_type::process< std::int32_t  >  );
             observe_param.insert( identificator_type::template get< std::int64_t   >(), &this_type::process< std::int64_t  >  );
             observe_param.insert( identificator_type::template get< std::uint8_t   >(), &this_type::process< std::uint8_t  >  );
             observe_param.insert( identificator_type::template get< std::uint16_t  >(), &this_type::process< std::uint16_t >  );
             observe_param.insert( identificator_type::template get< std::uint32_t  >(), &this_type::process< std::uint32_t >  );
             observe_param.insert( identificator_type::template get< std::uint64_t  >(), &this_type::process< std::uint64_t >  );

             observe_param.insert( identificator_type::template get<       float    >(), &this_type::process<     float    >  );
             observe_param.insert( identificator_type::template get<      double    >(), &this_type::process<    double    >  );
             observe_param.insert( identificator_type::template get<  long double   >(), &this_type::process<long double   >  );

             observe_param.insert( identificator_type::template get< short          >(), &this_type::process< short          >  );
             observe_param.insert( identificator_type::template get< unsigned short >(), &this_type::process< unsigned short >  );
             observe_param.insert( identificator_type::template get< int            >(), &this_type::process< int            >  );
             observe_param.insert( identificator_type::template get< unsigned       >(), &this_type::process< unsigned       >  );
             observe_param.insert( identificator_type::template get< long           >(), &this_type::process< long           >  );
             observe_param.insert( identificator_type::template get< long long      >(), &this_type::process< long long      >  );
             observe_param.insert( identificator_type::template get< unsigned long     >(), &this_type::process< unsigned long          > );
             observe_param.insert( identificator_type::template get< unsigned long long>(), &this_type::process< unsigned long long     > );

             observe_param.insert( identificator_type::template get< void*         >(), &this_type::process< void*         >  );
             observe_param.insert( identificator_type::template get< nullptr_t     >(), &this_type::null   );

             observe_param.insert( identificator_type::template get< std::string  >(), &this_type::process< std::string  >  );
             observe_param.insert( identificator_type::template get< std::wstring >(), &this_type::process< std::wstring >  );

             {
              using namespace std::placeholders;
              auto f = std::bind( &this_type::structure, std::ref(observe_param), _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  structure_type      >(), f );
             }

            }

         public:
           template
            <
              typename       fundamental_name
             ,typename      image_name = typename std::add_lvalue_reference< typename std::add_const<fundamental_name>::type >::type
             ,typename   original_name = typename std::add_lvalue_reference< fundamental_name >::type
             ,typename      model_name = typename std::add_lvalue_reference< typename std::add_const<fundamental_name>::type >::type
            >
           static error_enum process( structure_type & output_param, key_type const& key_param, property_type const& right_param )
            {
             auto iterator = output_param.find( key_param );
             if( output_param.end() == iterator )
              {
               return left_not_found_index;
              }

             property_type *  left = dynamic_cast< property_type * >( output_param.data( iterator ).get() );
             if( nullptr == left )
              {
               return left_not_property_index;
              }

             if( false == ::reflection::property::assign<fundamental_name, error_enum, image_name, original_name, model_name >( *left, right_param ) )
              {
               return assign_fail_index;
              }

             return true_index;
            }

           static error_enum structure( observe_type const& observe_param, output_type & output_param, key_type const& key_param, property_type const& property_param )
            {
             if( false == ::reflection::property::inspect::check < structure_type const& >( property_param ) )
             {
               return left_not_structure_index;
             }
             auto sub = ::reflection::property::inspect::present< structure_type const& >( property_param );
             observe_param.view( output_param, sub );

             return true_index;
            }

           static error_enum null     ( output_type & output_param, key_type const& key_param, property_type const& property_param )
            {
             typedef ::reflection::property::null_class null_type;
             auto null = dynamic_cast< null_type const* >( &property_param );
             if( nullptr == null )
              {
               return false_index;
              }

             return true_index;
            }

        };

     }
   }
 }

#endif
