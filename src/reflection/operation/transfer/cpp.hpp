#ifndef reflection_operation_transfer_cpp
#define reflection_operation_transfer_cpp

// ::reflection::operation::transfer::cpp_class<output_name,key_name,type_name>

#include "../../content/category.hpp"
#include "../../content/function/algorithm.hpp"
#include "../../content/typedef/typedef.hpp"
#include "../../content/enum/enum.hpp"
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
       struct cpp_struct
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
           cpp_struct( observe_type & observe_param )
            {
             observe_param.control( observe_type::recover_not_category_index  , &cpp_struct::recover );
           //observe_param.control( observe_type::recover_missing_action_index, &cpp_struct::recover );
             observe_param.control( observe_type::recover_action_fail_index   , &cpp_struct::recover );

             observe_param.control( observe_type::stage_prologue_index,   &cpp_struct::prologue );
             observe_param.control( observe_type::stage_argument_index,   &cpp_struct::argument );
             observe_param.control( observe_type::stage_contrast_index,   &cpp_struct::contrast );
             observe_param.control( observe_type::stage_exodus_index,     &cpp_struct::exodus   );

             observe_param.insert( identificator_type::template get< std::string    >(), &cpp_struct::primitive<std::string   >  );
     // TODO observe_param.insert( identificator_type::template get<  std::wstring  >(), &cpp_struct::primitive<std::wstring  >  );

             observe_param.insert( identificator_type::template get<  char           >(), &cpp_struct::primitive<char          >  );
             observe_param.insert( identificator_type::template get<  unsigned char  >(), &cpp_struct::primitive<unsigned char >  );
             observe_param.insert( identificator_type::template get<  wchar_t        >(), &cpp_struct::primitive<wchar_t  >  );
             observe_param.insert( identificator_type::template get<  std::wint_t    >(), &cpp_struct::primitive<std::wint_t   >  );

             observe_param.insert( identificator_type::template get<  std::int8_t    >(), &cpp_struct::primitive<std::int8_t   >  );
             observe_param.insert( identificator_type::template get<  std::int16_t   >(), &cpp_struct::primitive<std::int16_t  >  );
             observe_param.insert( identificator_type::template get<  std::int32_t   >(), &cpp_struct::primitive<std::int32_t  >  );
             observe_param.insert( identificator_type::template get<  std::int64_t   >(), &cpp_struct::primitive<std::int64_t  >  );

             observe_param.insert( identificator_type::template get<  std::uint8_t   >(), &cpp_struct::primitive<std::uint8_t  >  );
             observe_param.insert( identificator_type::template get<  std::uint16_t  >(), &cpp_struct::primitive<std::uint16_t >  );
             observe_param.insert( identificator_type::template get<  std::uint32_t  >(), &cpp_struct::primitive<std::uint32_t >  );
             observe_param.insert( identificator_type::template get<  std::uint64_t  >(), &cpp_struct::primitive<std::uint64_t >  );

             observe_param.insert( identificator_type::template get<       float     >(), &cpp_struct::primitive<     float    >  );
             observe_param.insert( identificator_type::template get<      double     >(), &cpp_struct::primitive<    double    >  );
             observe_param.insert( identificator_type::template get<  long double    >(), &cpp_struct::primitive<long double   >  );

             observe_param.insert( identificator_type::template get<  void*          >(), &cpp_struct::primitive<void*         >  );
             observe_param.insert( identificator_type::template get<  short          >(), &cpp_struct::primitive<short         >  );
             observe_param.insert( identificator_type::template get<  unsigned short >(), &cpp_struct::primitive<unsigned short>  );
             observe_param.insert( identificator_type::template get<  int            >(), &cpp_struct::primitive<int           >  );
             observe_param.insert( identificator_type::template get<  unsigned       >(), &cpp_struct::primitive<unsigned      >  );
             observe_param.insert( identificator_type::template get<  long           >(), &cpp_struct::primitive<long          >  );
             observe_param.insert( identificator_type::template get<  long long      >(), &cpp_struct::primitive<long long     >  );

             observe_param.insert( identificator_type::template get<  nullptr_t     >(), &cpp_struct::null   );

             {
              using namespace std::placeholders;
              auto f = std::bind( &cpp_struct::enumeration, _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  enumeration_context_type      >(), f );
             }

             {
              using namespace std::placeholders;
              auto f = std::bind( &cpp_struct::function, _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  algorithm_type      >(), f );
             }

             {
              using namespace std::placeholders;
              auto f = std::bind( &cpp_struct::typedefinition, _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  typedefinition_context_type      >(), f );
             }

             {
              using namespace std::placeholders;
              auto f = std::bind( &cpp_struct::structure, _1, std::ref(observe_param), _2, _3 );
              observe_param.insert( identificator_type::template get<  structure_type      >(), f );
              observe_param.control( observe_type::recover_missing_action_index, f );
             }

            }

         private:
           typedef    std::string       string_type;
           typedef    std::wstring     wstring_type;
           typedef    bool             boolean_type;

           static  report_type   prologue( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param <<  "class TODO" << std::endl;
             
             output_param <<  "  {" << std::endl;
             return report_type( true );
            }

           static  report_type   argument( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             report_type result = true;

             {
              category_type const* category = dynamic_cast< category_type const* >( &property_param );
              if( nullptr != category )
               {
                output_param << category->identifier() << " ";
                result = true;
               }
              else
               {
                output_param << " //! Can not detect type ";
                result = false;
               }
             }

             return report_type( result );
            }

           static  report_type   contrast( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param <<  ";" << std::endl;
             return report_type( true );
            }

           static  report_type   stasimon( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             return report_type( true );
            }

           static  report_type   exodus ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << std::endl;
            output_param <<  "};" << std::endl;
             return report_type( true );
            }

           static  report_type   recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << "; // Continue like nothing happen.";

             return report_type( true );
            }

           static report_type null     ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             typedef ::reflection::property::null_class null_type;
             auto null = dynamic_cast< null_type const* >( &property_param );
             if( nullptr == null )
              {
               return report_type( false );
              }

             output_param << "NULL;";

             return report_type( true );
            }

           template< typename simple_name >
            static report_type primitive( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
             {
              boolean_type pass = true;

              output_param << key_param <<" " ;

              if( true == pass )
               {
                typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect_instance )
                 {
                  output_param << " = " << inspect_instance->present();
                  pass = false;
                 }
               }

              if( true == pass )
               {
                typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  output_param << " = " << direct_instance->disclose();
                  pass = false;
                 }
               }

              if( true == pass )
               {
                output_param << "  // <note message=\"Can not retrieve value\" />";
               }

              return report_type( true );
             }

           static report_type enumeration( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             enumeration_context_type  const* context = dynamic_cast< enumeration_context_type const* >( &property_param );
             if( nullptr == context )
              {
               output_param << "// < note=\"Wrong type supplied.\" /> ";
               return report_type( false );
              }

             //output_param <<  key_param;
             output_param << "enum "<< context->name() <<" { ";

             for( std::size_t index=0; index < context->container().size(); ++index )
              {
               output_param << context->container()[index].name()  << " =  ";
               output_param << context->container()[index].value() ;
               if( index +1 < context->container().size() ) output_param << ",";
              }
             output_param << "} ";

             //output_param << std::endl;

             return report_type( true );
            }

           static report_type function ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             algorithm_type  const* context = dynamic_cast< algorithm_type const* >( &property_param );
             if( nullptr == context )
              {
               output_param << " // < note=\"Wrong type supplied.\" /> ";
               return report_type( false );
              }

             output_param << context->signature()[0] << " ";

             output_param << key_param <<"( " ;

             for( std::size_t index=1; index < context->signature().size(); ++index )
              {
               if( context->signature()[index] == identificator_type::NAT() )
                {
                 continue;
                }

               output_param << context->signature()[index];
               if( index + 1 < context->signature().size() ) output_param <<  ", ";
              }
             output_param << ")";

             //output_param << std::endl;
             return report_type( true );
            }

           static report_type typedefinition ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             typedefinition_context_type  const* context = dynamic_cast< typedefinition_context_type const* >( &property_param );
             if( nullptr == context )
              {
               output_param << "<note=\"Wrong type supplied.\" .>";
               return report_type( false );
              }

             output_param << "typedef  " << context->name();

             //output_param << std::endl;

             return report_type( true );
            }

           static  report_type structure( output_type & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_reference_type property_param  )
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

             //output_param << std::endl;
             return report_type( true );
            }

       };

     }
   }
 }

#endif
