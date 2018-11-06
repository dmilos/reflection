#ifndef reflection_operation_assign
#define reflection_operation_assign

// ::reflection::operation::transfer::assign<key_name>

#include "../../content/category.hpp"
#include "../../property/structure.hpp"
#include "../../operation/transfer/observe.hpp"

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
        ,template  < typename > class qualificator_name = std::add_const
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct assign_struct
        {
         public:
           typedef     key_name        key_type;
           typedef    identifier_name       identifier_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<identifier_type>       category_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef typename qualificator_name< property_type >::type                       property_qualified_type;
           typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           typedef  structure_type                output_type;

           enum error_enum
            {
             false_index               = (false),
             true_index                = (true),
             left_not_found_index      = true_index + 1,
             left_not_property_index   = true_index + 2,
             left_not_structure_index  = true_index + 3,
             assign_fail_index         = true_index + 4,
            };

           typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, error_enum, std::add_const, container_name > observe_type;

         public:
           assign_struct( observe_type & observe_param )
            {
             observe_param.insert( identificator_type::template get<  std::string    >(), &assign_struct::process<std::string   >  );
             observe_param.insert( identificator_type::template get<  std::wstring   >(), &assign_struct::process<std::wstring  >  );

             observe_param.insert( identificator_type::template get<  char           >(), &assign_struct::process<char          >  );
             observe_param.insert( identificator_type::template get<  unsigned char  >(), &assign_struct::process<unsigned char >  );
             observe_param.insert( identificator_type::template get<  wchar_t        >(), &assign_struct::process<wchar_t  >  );
             observe_param.insert( identificator_type::template get<  std::wint_t    >(), &assign_struct::process<std::wint_t   >  );

             observe_param.insert( identificator_type::template get<  std::int8_t    >(), &assign_struct::process<std::int8_t   >  );
             observe_param.insert( identificator_type::template get<  std::int16_t   >(), &assign_struct::process<std::int16_t  >  );
             observe_param.insert( identificator_type::template get<  std::int32_t   >(), &assign_struct::process<std::int32_t  >  );
             observe_param.insert( identificator_type::template get<  std::int64_t   >(), &assign_struct::process<std::int64_t  >  );

             observe_param.insert( identificator_type::template get<  std::uint8_t   >(), &assign_struct::process<std::uint8_t  >  );
             observe_param.insert( identificator_type::template get<  std::uint16_t  >(), &assign_struct::process<std::uint16_t >  );
             observe_param.insert( identificator_type::template get<  std::uint32_t  >(), &assign_struct::process<std::uint32_t >  );
             observe_param.insert( identificator_type::template get<  std::uint64_t  >(), &assign_struct::process<std::uint64_t >  );

             observe_param.insert( identificator_type::template get<       float     >(), &assign_struct::process<     float    >  );
             observe_param.insert( identificator_type::template get<      double     >(), &assign_struct::process<    double    >  );
             observe_param.insert( identificator_type::template get<  long double    >(), &assign_struct::process<long double   >  );

             observe_param.insert( identificator_type::template get<  void*          >(), &assign_struct::process<void*         >  );
             observe_param.insert( identificator_type::template get<  short          >(), &assign_struct::process<short         >  );
             observe_param.insert( identificator_type::template get<  unsigned short >(), &assign_struct::process<unsigned short>  );
             observe_param.insert( identificator_type::template get<  int            >(), &assign_struct::process<int           >  );
             observe_param.insert( identificator_type::template get<  unsigned       >(), &assign_struct::process<unsigned      >  );
             observe_param.insert( identificator_type::template get<  long           >(), &assign_struct::process<long          >  );
             observe_param.insert( identificator_type::template get<  long long      >(), &assign_struct::process<long long     >  );

             observe_param.insert( identificator_type::template get<  nullptr_t     >(), &assign_struct::null   );

             {
              using namespace std::placeholders;
              auto f = std::bind( &assign_struct::structure, _1, std::ref(observe_param), _2, _3 );
              observe_param.insert( identificator_type::template get<  structure_type      >(), f );
             }

            }

         public:
           template
            <
              typename       primitive_name
             ,typename      image_name = typename std::add_lvalue_reference< typename std::add_const<primitive_name>::type >::type
             ,typename   original_name = typename std::add_lvalue_reference< primitive_name >::type
             ,typename      model_name = typename std::add_lvalue_reference< typename std::add_const<primitive_name>::type >::type
            >
           static error_enum process( structure_type & output_param, key_type const& key_param, property_qualified_reference_type right_param )
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

             if( false == ::reflection::property::assign<primitive_name, error_enum, image_name, original_name, model_name >( *left, right_param ) )
              {
               return assign_fail_index;
              }

             return true_index;
            }

           static error_enum structure( output_type & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             if( false == ::reflection::property::inspect::check < structure_type const& >( property_param ) )
             {
               return left_not_structure_index;
             }
             auto sub = ::reflection::property::inspect::present< structure_type const& >( property_param );
             observe_param.view( output_param, sub );

             return true_index;
            }

           static error_enum null     ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
