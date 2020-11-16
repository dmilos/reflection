#ifndef reflection_operation_transfer_ini_print
#define reflection_operation_transfer_ini_print

// ::reflection::operation::transfer::ini_class<output_name,key_name,type_name>

#include "../../../content/category.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/encode/observe.hpp"

#include "./context.hpp"





namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace ini
       {

        template
         <
           typename      output_name //!< conect operator << ()
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct print_struct //!< Windows ini file
          {
           private:
             typedef std::size_t size_type;
             typedef std::string  string_type;

           public:
             typedef ::reflection::operation::transfer::ini::context_struct<string_type> context_type;

           public:
             typedef std::shared_ptr< context_type >  context_pointer_type;
             static context_pointer_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef      output_name        output_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

             typedef ::reflection::operation::transfer::ini::print_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::encode::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>   enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit print_struct( observe_type & observe_param, context_pointer_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               observe_param.stage( observe_type::stage_introductum_index,  std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_prolog_index,  std::bind( &this_type::prolog, context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_epilog_index,  std::bind( &this_type::epilog, context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_prefix_index,  std::bind( &this_type::prefix, context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_suffix_index,  &this_type::suffix );

               observe_param.insert( identificator_type::template get< bool           >(), &this_type::fundamental< bool          >  );
               
               observe_param.insert( identificator_type::template get< char           >(), &this_type::fundamental< char          >  );
               observe_param.insert( identificator_type::template get< unsigned char  >(), &this_type::fundamental< unsigned char >  );
               observe_param.insert( identificator_type::template get< wchar_t        >(), &this_type::fundamental< wchar_t       >  );
               observe_param.insert( identificator_type::template get< std::wint_t    >(), &this_type::fundamental< std::wint_t   >  );
               observe_param.insert( identificator_type::template get< char16_t       >(), &this_type::fundamental< char16_t      >  );
               observe_param.insert( identificator_type::template get< char32_t       >(), &this_type::fundamental< char32_t      >  );

               observe_param.insert( identificator_type::template get< std::int8_t    >(), &this_type::fundamental< std::int8_t   >  );
               observe_param.insert( identificator_type::template get< std::int16_t   >(), &this_type::fundamental< std::int16_t  >  );
               observe_param.insert( identificator_type::template get< std::int32_t   >(), &this_type::fundamental< std::int32_t  >  );
               observe_param.insert( identificator_type::template get< std::int64_t   >(), &this_type::fundamental< std::int64_t  >  );
               observe_param.insert( identificator_type::template get< std::uint8_t   >(), &this_type::fundamental< std::uint8_t  >  );
               observe_param.insert( identificator_type::template get< std::uint16_t  >(), &this_type::fundamental< std::uint16_t >  );
               observe_param.insert( identificator_type::template get< std::uint32_t  >(), &this_type::fundamental< std::uint32_t >  );
               observe_param.insert( identificator_type::template get< std::uint64_t  >(), &this_type::fundamental< std::uint64_t >  );

               observe_param.insert( identificator_type::template get<       float     >(), &this_type::fundamental<     float    >  );
               observe_param.insert( identificator_type::template get<      double     >(), &this_type::fundamental<    double    >  );
               observe_param.insert( identificator_type::template get<  long double    >(), &this_type::fundamental<long double   >  );

               observe_param.insert( identificator_type::template get< short          >(), &this_type::fundamental< short         >  );
               observe_param.insert( identificator_type::template get< unsigned short >(), &this_type::fundamental< unsigned short>  );
               observe_param.insert( identificator_type::template get< int            >(), &this_type::fundamental< int           >  );
               observe_param.insert( identificator_type::template get< unsigned       >(), &this_type::fundamental< unsigned      >  );
               observe_param.insert( identificator_type::template get< long           >(), &this_type::fundamental< long          >  );
               observe_param.insert( identificator_type::template get< long long      >(), &this_type::fundamental< long long     >  );
               observe_param.insert( identificator_type::template get< unsigned long     >(), &this_type::fundamental< unsigned long          > );
               observe_param.insert( identificator_type::template get< unsigned long long>(), &this_type::fundamental< unsigned long long     > );

               observe_param.insert( identificator_type::template get< void*          >(), &this_type::fundamental<void*         >  );
               observe_param.insert( identificator_type::template get< nullptr_t      >(), &this_type::null_value   );

               observe_param.insert( identificator_type::template get< std::string   >(), &this_type::string   );
               observe_param.insert( identificator_type::template get< std::wstring  >(), &this_type::wstring  );

              }

           private:
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               return report_type( true );
              }
             static report_type introductum(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << "introductum" << std::endl;
               report_type result = true;
               context_param->m_isStructure = true;
               return result;
              }

             static report_type prolog(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << "prolog" << std::endl;
               report_type result = true;
               {
                category_type const* category = dynamic_cast< category_type const* >( &property_param );
                if( nullptr != category )
                 {
                  output_param <<"["
                       << key_param
                       << "("
                       << category->identifier()
                       << ")"
                       << "]";
                  result = true;
                  context_param->m_isStructure = true;
                 }
                else
                 {
                  output_param << " //! Can not detect type ";
                  result = false;
                 }
               }
               output_param << std::endl;

               return result;
             }

             static report_type epilog(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << "epilog" << std::endl;
               return true;
              }

             static report_type prefix(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << "prefix" << std::endl;
               report_type result = true;

               {
                category_type const* category = dynamic_cast< category_type const* >( &property_param );
                if( nullptr != category )
                 {
                  if( category->identifier() == identificator_type::template get<  algorithm_type      >()  ) return report_type( true );
                  if( category->identifier() == identificator_type::template get<  typedefinition_type >()  ) return report_type( true );
                  if( category->identifier() == identificator_type::template get<  enumeration_type    >()  ) return report_type( true );
                 }
                else
                 {
                  output_param << " # Can not detect type ";
                  result = false;
                 }
               }

               //if( true == context_param->m_isStructure )
               // {
               //  context_param->m_isStructure = false;
               //  return report_type( result );
               // }

               output_param <<  key_param <<  " = ";

               return report_type( result );
              }

             static report_type suffix( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << std::endl;
               output_param << "suffix" << std::endl;
               return report_type( true );
              }

             static report_type null_value  ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null )
                {
                 return report_type( false );
                }

               output_param << "null" << std::endl;
               return report_type( true );
              }

             static report_type string(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  output_param << "    " <<  inspect->present();
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  output_param << "    "<<  direct_instance->disclose() << "\"";
                  return report_type( true );
                 }
               }
               output_param << " 0 #    \"" << "note" << "\"" << ": " << "\""<<  "Can not retrieve the value." << "\"";
               return report_type( true );
              }

             static report_type wstring(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  // TODO output_param << "    " << "  inspect->present();
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  // TODO output_param << "    "<<  direct_instance->disclose() << "\"";
                  return report_type( true );
                 }
               }

               return report_type( true );
              }

             template< typename simple_name >
              static report_type fundamental(  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                {
                 typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   output_param << " " << inspect_instance->present();
                   return report_type( true );
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   output_param << " " << direct_instance->disclose();
                   return report_type( true );
                  }
                }

                {
                 output_param << " 0 #   \"note\" : " << "\"Can not retrieve value.\"";
                }

                return report_type( true );
               }

         };

       }
     }
   }
 }

#endif
