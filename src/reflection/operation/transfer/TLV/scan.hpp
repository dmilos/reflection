#ifndef reflection_operation_transfer_tlv_scan
#define reflection_operation_transfer_tlv_scan

// ::reflection::operation::transfer::tlv::scan_struct<input_name,key_name,identifier_name,report_name,container_name>

#include "../../../type/name/id.hpp"

#include "../../../content/guarded/simple.hpp"
#include "./context.hpp"
#include "./overload.hpp"

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
           typename       input_name
          ,typename  identifier_name = std::string
          ,typename         key_name = std::string
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
          ,typename      report_name = bool
         >
         struct scan_struct
          {
           public:
             typedef      input_name          input_type;
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
             typedef ::reflection::operation::transfer::tlv::scan_struct<input_name,identifier_name,key_name, container_name, report_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;

             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::tlv::contractor_type<input_name,identifier_name,key_name,container_name,report_name> contractor_type;
             typedef typename contractor_type::facility_type::property_pointer_type    property_pointer_type;
             typedef typename contractor_type::facility_type::constructor_pointer_type  constructor_pointer_type;

             typedef ::reflection::operation::transfer::tlv::probe_class<identifier_name,report_name>   probe_type;

           public:
             explicit scan_struct( contractor_type &  contractor_param, context_pointer_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               this_type::template register_basic<int>(         context_param, contractor_param );
               this_type::template register_basic<float>(       context_param, contractor_param );
               this_type::template register_basic<double>(      context_param, contractor_param );
               this_type::template register_basic<long double>( context_param, contractor_param );
               this_type::template register_basic<long int >(   context_param, contractor_param );
               //this_type::register_string(   context_param, contractor_param );

               contractor_param.probe(      typename contractor_type::probe_pointer_type(       new ::reflection::operation::transfer::tlv::probe_class<std::string, bool>{} ) );
               contractor_param.accumulator( typename contractor_type::accumulator_pointer_type(  new ::reflection::operation::transfer::tlv::accumulator_class< input_name,std::string, bool>{} ) );
               contractor_param.recover(    typename contractor_type::recover_pointer_type(     new ::reflection::operation::transfer::tlv::recover_class< std::string, bool>{} ) );
               contractor_param.sentinel(   typename contractor_type::sentinel_pointer_type(    new ::reflection::operation::transfer::tlv::sentinel_class<  bool>{} ) );
              }

           public:
             template < typename data_name >
              static  property_pointer_type read_basic( context_pointer_type &context_param, input_type& input_param )
               {
                typedef typename ::reflection::content::guarded::simple_struct<std::string,data_name>::typedef_type simple_type;

                size_type size;
                auto current_position = input_param.tellg();
                if( current_position == probe_type::get_size( *context_param, size, input_param ) )
                 {
                  return property_pointer_type( nullptr );
                 }

                data_name value;
                input_param.read( reinterpret_cast<char*>( &value ), sizeof( value ) );
                return property_pointer_type( new simple_type( value ) );
               }

           public:
             static property_pointer_type read_string( context_pointer_type &context_param, input_name & input_param  )
              {
               typedef typename ::reflection::content::guarded::simple_struct<std::string,std::string>::typedef_type simple_type;

                size_type size;
                auto current_position = input_param.tellg();
                if( current_position == probe_type::get_size( *context_param, size, input_param ) )
                 {
                  return property_pointer_type( nullptr );
                 }

               std::string value;
               value.resize( size );
               input_param.read( const_cast<char*>( reinterpret_cast<const char*>( value.data() ) ), size );
               return property_pointer_type( new simple_type( value ) );
              }

           public:
             template < typename simple_name >
              static void register_basic( context_pointer_type &context_param, contractor_type &  contractor_param )
               {
                typedef ::reflection::operation::transfer::tlv::_internal::overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = contractor_param.facility();

                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::read_basic< simple_name>, context_param, std::placeholders::_1 );

                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<simple_name>( constructor );
               }

             //template < typename simple_name >
             // static void register_vector_simple( contractor_type &  contractor_param )
             //  {
             //   typedef overload_class<property_pointer_type,input_type& >;
             //   auto & facility = contractor_param.facility();
             //   auto constructor = constructor_pointer_type(  new overload_class( & this_type::template read_basic<simple_name>) );
             //
             //   facility.template insert<simple_name>( constructor );
             //  }

             //template < typename simple_name >
             // static void register_container( contractor_type &  contractor_param )
             //  {
             //   typedef overload_class<property_pointer_type,input_type& >;
             //   auto & facility = contractor_param.facility();
             //   auto constructor = constructor_pointer_type(  new overload_class( & this_type::template read_basic<simple_name>) );
             //
             //   facility.template insert<simple_name>( constructor );
             //  }

          };

       }
     }
   }
 }

#endif
