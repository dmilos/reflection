#ifndef  reflection_operation_transfer_tlv_serialize
#define reflection_operation_transfer_tlv_serialize

// ::reflection::operation::transfer::tlv::serialize_struct<output_name,key_name,identifier_name,report_name,container_name>

#include "../../../type/name/id.hpp"

#include "../../../content/category.hpp"
#include "../../../content/function/algorithm.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/encode/observe.hpp"

#include "./context.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace tlv
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
             typedef std::size_t   size_type;
             typedef std::string string_type;

             typedef ::reflection::operation::transfer::tlv::context_struct<size_type> context_type;

           public:
             typedef std::shared_ptr< context_type >  context_pointer_type;
             static context_pointer_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::tlv::serialize_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::encode::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>           enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit serialize_struct( observe_type & observe_param, context_pointer_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::structure, std::ref(observe_param), context_param, _1,_2, _3 );
                auto i = identificator_type::template get<  structure_type      >();
                observe_param.insert( i, f );
                observe_param.recover( observe_type::recover_action_acquisition_index   , f );
               }

               observe_param.insert( identificator_type::template get<  std::string    >(), std::bind( &this_type::string , context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  bool           >(), std::bind( &this_type::primitive<bool          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  char           >(), std::bind( &this_type::primitive<char          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  unsigned char  >(), std::bind( &this_type::primitive<unsigned char >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  wchar_t        >(), std::bind( &this_type::primitive<wchar_t       >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::wint_t    >(), std::bind( &this_type::primitive<std::wint_t   >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  std::int8_t    >(), std::bind( &this_type::primitive<std::int8_t   >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::int16_t   >(), std::bind( &this_type::primitive<std::int16_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::int32_t   >(), std::bind( &this_type::primitive<std::int32_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::int64_t   >(), std::bind( &this_type::primitive<std::int64_t  >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  std::uint8_t   >(), std::bind( &this_type::primitive<std::uint8_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::uint16_t  >(), std::bind( &this_type::primitive<std::uint16_t >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::uint32_t  >(), std::bind( &this_type::primitive<std::uint32_t >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  std::uint64_t  >(), std::bind( &this_type::primitive<std::uint64_t >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<       float     >(), std::bind( &this_type::primitive<     float    >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<      double     >(), std::bind( &this_type::primitive<    double    >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  long double    >(), std::bind( &this_type::primitive<long double   >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  void*          >(), std::bind( &this_type::primitive<void*         >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  short          >(), std::bind( &this_type::primitive<short         >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  unsigned short >(), std::bind( &this_type::primitive<unsigned short>, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  int            >(), std::bind( &this_type::primitive<int           >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  unsigned       >(), std::bind( &this_type::primitive<unsigned      >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  long           >(), std::bind( &this_type::primitive<long          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  long long      >(), std::bind( &this_type::primitive<long long     >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned long     >(), std::bind( &this_type::primitive< unsigned long          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned long long>(), std::bind( &this_type::primitive< unsigned long long     >, context_param, _1, _2, _3 ) );
              }

           private:
             typedef    bool             boolean_type;
           private:
            static bool output_size( size_type const& size_param,  context_pointer_type const &context_param, output_type & output_param  )
              {
               switch( context_param->size_size )
                {
                 case( 1 ):{ std::uint8_t  s = size_param; output_param.write( reinterpret_cast<char*>( & s), 1 ); } break; // TODO check return of write
                 case( 2 ):{ std::uint16_t s = size_param; output_param.write( reinterpret_cast<char*>( & s), 2 ); } break; // TODO check return of write
                 case( 4 ):{ std::uint32_t s = size_param; output_param.write( reinterpret_cast<char*>( & s), 4 ); } break; // TODO check return of write
                 case( 8 ):{ std::uint64_t s = size_param; output_param.write( reinterpret_cast<char*>( & s), 8 ); } break; // TODO check return of write
                 default: return false;
                }
               return true;
              }

            static bool output_chunk( size_type const& size_param,  const void * data_param,  context_pointer_type const &context_param,output_type & output_param  )
              {
               output_size( size_param, context_param, output_param );
               output_param.write( reinterpret_cast< const char * >( data_param ), size_param );              
               return true;
              }

           private:
             static report_type string (                                            context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef std::string string_type;
               auto const& id = identificator_type::template get<string_type>();
                {
                 typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   output_chunk( id.size(), id.data(), context_param, output_param );
                   output_chunk( key_param.size(), key_param.data(), context_param, output_param );

                   string_type const& value = inspect_instance->present();
                   output_chunk( value.size(), value.data(), context_param, output_param );

                   return report_type( true );
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   output_chunk( id.size(), id.data(), context_param, output_param );
                   output_chunk( key_param.size(), key_param.data(), context_param, output_param );

                   string_type const& value = direct_instance->disclose();
                   output_chunk( value.size(), value.data(), context_param, output_param );

                   return report_type( true );
                  }
                }
               return report_type( true );
              }

           private:
             template< typename simple_name >
              static report_type primitive(                                         context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                auto const& id = identificator_type::template get<simple_name>();
                {
                 typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   output_chunk( id.size(), id.data(), context_param, output_param );
                   output_chunk( key_param.size(), key_param.data(), context_param, output_param );

                   simple_name value = inspect_instance->present();
                   output_chunk( sizeof( simple_name ),  &value, context_param, output_param );

                   return report_type( true );
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   output_chunk( id.size(), identificator_type::template get<string_type>().data(), context_param, output_param );
                   output_chunk( key_param.size(), key_param.data(), context_param, output_param );

                   simple_name value = direct_instance->disclose();
                   output_chunk( sizeof( simple_name ),  &value, context_param, output_param );

                   return report_type( true );
                  }
                }

                return report_type( false );
               }

           private:
             static report_type structure (      observe_type const& observe_param, context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
                 // TODO
                }

               return report_type( true );
             }

           public:
             template< typename data_name, typename function_name  >
              static void register__any( function_name const& f, observe_type & observe_param, context_pointer_type &context_param )
               {
                using namespace std::placeholders;
                return observe_param.template register__any< data_name > ( std::bind( f, context_param, _1, _2, _3 ) );
               }

           public:
             template< typename data_name, typename view_name>
              static void register_class( observe_type & observe_param, context_pointer_type &context_param )
               {
                using namespace std::placeholders;
                auto f = std::bind( &observe_type::template view_custom<data_name, view_name>, std::ref(observe_param) , _1, _2, _3 );
                observe_param.template register__any< data_name >( f );
               }

          };

       }
     }
   }
 }

#endif
