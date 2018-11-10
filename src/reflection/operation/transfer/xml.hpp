#ifndef reflection_operation_transfer_xml
#define reflection_operation_transfer_xml

// ::reflection::operation::transfer::xml_class<output_name,key_name,type_name>

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
       struct xml_struct
        {
         private:
           typedef std::size_t size_type;
           struct internal_struct
            {
              size_type m_ident=0;
              void inc(){ ++m_ident; }
              void dec(){ --m_ident; }
             };

           typedef std::shared_ptr< internal_struct > internalPtr_type;

         public:
           typedef      output_name        output_type;
           typedef         key_name           key_type;
           typedef  identifier_name    identifier_type;
           typedef      report_name        report_type;

           typedef ::reflection::operation::transfer::xml_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<identifier_type>             category_type;
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
           xml_struct( observe_type & observe_param )
            {
             observe_param.control( observe_type::recover_not_category_index  , &this_type::recover );
           //observe_param.control( observe_type::recover_missing_action_index, &this_type::recover );
             observe_param.control( observe_type::recover_action_fail_index   , &this_type::recover );

             observe_param.control( observe_type::stage_introductum_index,    &this_type::introductum );
             observe_param.control( observe_type::stage_prefix_index,     &this_type::prefix  );
             observe_param.control( observe_type::stage_suffix_index,        &this_type::suffix     );
             observe_param.control( observe_type::stage_conclusio_index,     &this_type::conclusio  );

             observe_param.insert( identificator_type::template get< std::string    >(), &this_type::primitive<std::string   >  );
     // TODO observe_param.insert( identificator_type::template get<  std::wstring  >(), &this_type::primitive<std::wstring  >  );

             // TODO observe_param.insert( identificator_type::template get<  std::vector< property_type *>  >(), &this_type::vector  );
             // TODO observe_param.insert( identificator_type::template get<  std::set<    property_type *>  >(), &this_type::set     );

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

              observe_param.insert( identificator_type::template get<  enumeration_type      >(), &this_type::enumeration );
              observe_param.insert( identificator_type::template get<  algorithm_type      >(), &this_type::function);
              observe_param.insert( identificator_type::template get<          typedefinition_type      >(), &this_type::typedefinition );

             {
              using namespace std::placeholders;
              auto f = std::bind( &this_type::structure, _1, std::ref(observe_param), _2, _3 );
              observe_param.insert( identificator_type::template get<  structure_type      >(), f );
              observe_param.control( observe_type::recover_missing_action_index, f );
             }

            }

         private:
           typedef    std::string       string_type;
           typedef    std::wstring     wstring_type;
           typedef    bool             boolean_type;

           static report_type recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << "<message content=\"Continue like nothig happen.\" /> ";

             return report_type( true );
            }

           static report_type introductum( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param <<  "<element>" << std::endl;
             return report_type( true );
            }

           static report_type conclusio ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << std::endl;
             output_param <<  "</element>" << std::endl;
             return report_type( true );
            }

           static report_type prefix( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             report_type result = true;

             output_param << "<item ";
             output_param << "name=\"" << key_param << "\" ";

             {
              category_type const* category = dynamic_cast< category_type const* >( &property_param );
              if( nullptr != category )
               {
                output_param << "type=\"" << category->identifier() << "\" ";
                result = true;
               }
              else
               {
                output_param << "note=\"Can not detect type\" ";
                result = false;
               }
             }

             output_param << ">";
             return report_type( result );
            }

           static report_type suffix( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param <<  "</item>" << std::endl;
             return report_type( true );
            }

           static report_type stasimon( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             return report_type( true );
            }

           static report_type null_value( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

           template< typename simple_name >
            static report_type primitive( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

           static report_type enumeration( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             enumeration_type  const* context = dynamic_cast< enumeration_type const* >( &property_param );
             if( nullptr == context )
              {
               output_param << "< note=\"Wrong type supplied.\" /> ";
               return report_type( false );
              }

             output_param << std::endl;
             for( std::size_t index=0; index < context->container().size(); ++index )
              {
               output_param << "  <parameter ";
               output_param << "ordinal=\"" << index << "\" ";
               output_param << "value=\""   << context->container()[index].value() << "\" ";
               output_param << "name=\""    << context->container()[index].name()  << "\" ";
               output_param << "/>";
               output_param << std::endl;
              }

             //output_param << std::endl;

             return report_type( true );
            }

           static report_type function ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             algorithm_type  const* context = dynamic_cast< algorithm_type const* >( &property_param );
             if( nullptr == context )
              {
               output_param << "< note=\"Wrong type supplied.\" /> ";
               return report_type( false );
              }

             output_param << ">" << std::endl;
             for( std::size_t index=0; index < context->signature().size(); ++index )
              {
               if( context->signature()[index] == identificator_type::NAT() )
                {
                 continue;
                }

               output_param << "  <parameter ";
               output_param << "ordinal=\"" << index << "\" ";
               output_param << "type=\"" << context->signature()[index] << "\" ";
               output_param << "/>";
               output_param << std::endl;
              }

             //output_param << std::endl;
             return report_type( true );
            }

           static report_type typedefinition ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             typedefinition_type  const* context = dynamic_cast<         typedefinition_type const* >( &property_param );
             if( nullptr == context )
              {
               output_param << "<note=\"Wrong type supplied.\" .>";
               return report_type( false );
              }

             output_param << std::endl;
             output_param << "    <name   value=\"" << context->name() << "\" />";
             output_param << std::endl;
             output_param << "    <object value=\"" << context->object() << "\" />";
             output_param << std::endl;
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
