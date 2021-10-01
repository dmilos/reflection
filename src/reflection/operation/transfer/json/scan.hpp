#ifndef reflection_operation_transfer_json_scan
#define reflection_operation_transfer_json_scan

// ::reflection::operation::transfer::json::scan_struct<input_name,key_name,identifier_name,report_name,container_name>

#include "./context.hpp"

#include "../../../type/name/id.hpp"
#include "../../../content/guarded/simple.hpp"
#include "../../../utility/function/stdo.hpp"

#include "./parser.hpp"
#include "./probe.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace json
       {

        template
         <
           typename       input_name
          ,typename  identifier_name
          ,typename         key_name
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

             typedef ::reflection::operation::transfer::json::context_input_struct< string_type > context_input_type;

           public:
             typedef std::shared_ptr< context_input_type >  context_input_pointer_type;
             static context_input_pointer_type context(){ return std::make_shared<context_input_type>(); }

           public:
             typedef ::reflection::operation::transfer::json::scan_struct<input_name,identifier_name,key_name, container_name, report_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;

             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::json::parser_type<input_name,identifier_name,key_name,container_name,report_name> parser_type;
             typedef typename parser_type::facility_type::property_pointer_type    property_pointer_type;

             typedef typename parser_type::facility_type::constructor_pointer_type  constructor_pointer_type;

             typedef ::reflection::operation::scan::probe::base_class< input_name, identifier_name, key_name, report_name >    probe_base_type;
             typedef ::reflection::operation::transfer::json::probe_class<identifier_name,key_name,report_name>                probe_json_type;

             typedef ::reflection::operation::transfer::json::accumulator_class< input_name,identifier_name, key_name, report_name> accumulator_type;

           public:
             explicit scan_struct( parser_type &  parser_param, context_input_pointer_type context_param = this_type::context() )
              {
               parser_param.probe(       typename parser_type::probe_pointer_type(       new probe_json_type  {} ) );
               parser_param.accumulator( typename parser_type::accumulator_pointer_type( new accumulator_type {} ) );

               using namespace std::placeholders;

               this_type::template register_bool< bool              >( parser_param, context_param );

               this_type::template register_integral< char          >( parser_param, context_param );
               this_type::template register_natural< unsigned char  >( parser_param, context_param );
               this_type::template register_integral< wchar_t       >( parser_param, context_param );
               this_type::template register_integral< std::wint_t   >( parser_param, context_param );
               this_type::template register_integral< char16_t      >( parser_param, context_param );
               this_type::template register_integral< char32_t      >( parser_param, context_param );

               this_type::template register_natural<std::uint8_t >( parser_param, context_param );
               this_type::template register_natural<std::uint16_t>( parser_param, context_param );
               this_type::template register_natural<std::uint32_t>( parser_param, context_param );
               this_type::template register_natural<std::uint64_t>( parser_param, context_param );

               this_type::template register_integral<std::int8_t >( parser_param, context_param );
               this_type::template register_integral<std::int16_t>( parser_param, context_param );
               this_type::template register_integral<std::int32_t>( parser_param, context_param );
               this_type::template register_integral<std::int64_t>( parser_param, context_param );

               this_type::template register_decimal<float>(        parser_param, context_param );
               this_type::template register_decimal<double>(       parser_param, context_param );
               this_type::template register_decimal<long double>(  parser_param, context_param );

               // TODO this_type::template register_integral<void*      >(   parser_param, context_param  );
               this_type::template register_integral<short              >(   parser_param, context_param  );
               this_type::template register_natural<unsigned short     >(    parser_param, context_param  );
               this_type::template register_integral<int                >(   parser_param, context_param  );
               this_type::template register_natural<unsigned           >(    parser_param, context_param  );
               this_type::template register_integral<long               >(   parser_param, context_param  );
               this_type::template register_integral<long long          >(   parser_param, context_param  );
               this_type::template register_natural<unsigned long      >(    parser_param, context_param  );
               this_type::template register_natural<unsigned long long >(    parser_param, context_param  );

               this_type::register_string< char     >(  parser_param, context_param  );
               //  TODO this_type::register_string< wchar_t  >(  parser_param, context_param  );
               //  TODO this_type::register_string< char16_t >(  parser_param, context_param  );
               //  TODO this_type::register_string< char32_t >(  parser_param, context_param  );
              }

           private:
              static  property_pointer_type read_bool( context_input_pointer_type &context_param, input_type& input_param )
               { //std::cout << __func__ << " - "<< __LINE__ << std::endl;
                typedef char char_type;
                typedef typename ::reflection::content::guarded::simple_struct<identifier_type,bool>::typedef_type simple_type;

                string_type true_string="true", false_string="true";
                auto current_position = input_param.tellg();

                // TODO take first char, check against T or F,
                // TODO parse rest of characters.

                bool value = true;

                return property_pointer_type( new simple_type( value ) );
               }

           public:

           public:
             template < typename data_name, typename function_name >
              static void register__any( function_name const& function_param, parser_type &  parser_param )
               {
                auto & facility = parser_param.facility();

                typedef std::function< property_pointer_type ( input_name& ) > constructor_input_type;
                constructor_input_type constructor_wrapped = std::bind( function_param, std::placeholders::_1 );

                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto constructor_pointer = constructor_pointer_type( new overload_type( constructor_wrapped ) );
                facility.template insert<data_name>( constructor_pointer );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<data_name>();
               }

           public:
             template < typename simple_name >
              static void register_bool( parser_type & parser_param, context_input_pointer_type &context_param )
               {
                return register__any<bool>( std::bind( &this_type::read_bool, context_param, std::placeholders::_1 ), parser_param );
               }

           private:
             template < typename data_name >
              static  property_pointer_type read_natural( context_input_pointer_type &context_param, input_type& input_param )
               { //std::cout << __func__ << " - "<< __LINE__ << std::endl;
                typedef char char_type;
                typedef typename ::reflection::content::guarded::simple_struct<identifier_type,data_name>::typedef_type simple_type;
                bool succes = false;
                auto start_position = input_param.tellg();

                data_name value = 0;
                data_name power = 1;
                while( true )
                 {
                  if( true == input_param.eof() ){ break; }
                  char_type  current;
                  input_param.get( current );
                  if( 0 != isdigit( current ) )
                   {
                    value = value * 10 + ( current - '0' );
                    succes = true;
                    continue;
                   }
                  input_param.unget();
                  break;
                 }

                if( false == succes )
                 {
                  input_param.seekg( start_position, std::ios_base::beg );
                  return property_pointer_type( nullptr );
                 }
                //std::cout << __func__ << " - "<< __LINE__ << " - " << value << std::endl;
                return property_pointer_type( new simple_type( value ) );
               }

           public:
             template < typename simple_name >
              static void register_natural( parser_type &  parser_param, context_input_pointer_type &context_param )
               {
                return register__any<simple_name>( std::bind( &this_type::read_natural<simple_name>, context_param, std::placeholders::_1 ), parser_param );
               }

           private:
             template < typename data_name >
              static  property_pointer_type read_integral( context_input_pointer_type &context_param, input_type& input_param )
              {  //std::cout << __func__ << " - "<< __LINE__ << std::endl;

               auto current_position = input_param.tellg();
               data_name value;
               if( false == probe_json_type::read_integral( *context_param, input_param, value  ) )
                {
                 return property_pointer_type( nullptr );
                }

               //std::cout << __func__ << " - "<< __LINE__ << " - \"" << value << "\"" << std::endl;
               typedef typename ::reflection::content::guarded::simple_struct<identifier_type,data_name>::typedef_type simple_type;
               return property_pointer_type( new simple_type( value ) );
              }

           public:
             template < typename simple_name >
              static void register_integral( parser_type &  parser_param, context_input_pointer_type &context_param )
               {
                return register__any<simple_name>( std::bind( &this_type::read_integral<simple_name>, context_param, std::placeholders::_1 ), parser_param );
               }

           public:
             template < typename data_name >
              static  property_pointer_type read_decimal( context_input_pointer_type &context_param, input_type& input_param )
              {  //std::cout << __func__ << " - "<< __LINE__ << std::endl;
               auto current_position = input_param.tellg();
               data_name value;
               if( false == probe_json_type::read_decimal( *context_param, input_param, value  ) )
                {
                 return property_pointer_type( nullptr );
                }

               //std::cout << __func__ << " - "<< __LINE__ << " - \"" << value << "\"" << std::endl;
               typedef typename ::reflection::content::guarded::simple_struct<identifier_type,data_name>::typedef_type simple_type;
               return property_pointer_type( new simple_type( value ) );
              }

           public:
             template < typename simple_name >
              static void register_decimal( parser_type &  parser_param, context_input_pointer_type &context_param )
               {
                return register__any<simple_name>( std::bind( &this_type::read_decimal<simple_name>, context_param, std::placeholders::_1 ), parser_param );
               }

           private:
             template < typename char_name >
              static property_pointer_type read_string( context_input_pointer_type &context_param, input_name & input_param  )
              {  //std::cout << __func__ << " - "<< __LINE__ << std::endl;
               typedef std::basic_string<char_name> string_local_type;

               auto current_position = input_param.tellg();
               string_local_type value;
               if( false == probe_json_type::quoted( *context_param, input_param, value, '"' ) )
                {
                 return property_pointer_type( nullptr );
                }

               //std::cout << __func__ << " - "<< __LINE__ << " - \"" << value << "\"" << std::endl;
               typedef typename ::reflection::content::guarded::simple_struct<identifier_type,string_local_type>::typedef_type simple_type;
               return property_pointer_type( new simple_type( value ) );
              }
           public:
             template < typename char_name >
              static void register_string( parser_type &  parser_param, context_input_pointer_type &context_param )
               {
                return register__any< std::basic_string<char_name> >( std::bind( &this_type::read_string<char_name>, context_param, std::placeholders::_1 ), parser_param );
               }

           private:
             template < typename class_name, typename view_name >
              static  property_pointer_type read_class( parser_type &  parser_param, context_input_pointer_type &context_param, input_type& input_param )
               {
                typedef typename ::reflection::content::trinity::simple_struct<identifier_type,class_name>::typedef_type simple_type;

                auto pile =  new simple_type();

                view_name view;
                view.pointer( &( pile->disclose()) );

                //std::cout << __func__ << " - "<< __LINE__ << " - " << "begin" << std::endl;

                auto start_position = input_param.tellg();

                probe_json_type::space( *context_param, input_param );
                if( false == probe_json_type::character( *context_param, input_param, '{' ) )
                 { // TODO input_param.seekg( current_position )
                  return property_pointer_type( nullptr );
                 } probe_json_type::space( *context_param, input_param );

                dynamic_cast< probe_base_type &>( *parser_param.probe() ).push();
                parser_param.parse( view, input_param );
                dynamic_cast< probe_base_type &>( *parser_param.probe() ).pop();

                probe_json_type::space( *context_param, input_param );
                if( false == probe_json_type::character( *context_param, input_param, '}' ) )
                 { // TODO input_param.seekg( current_position )
                  return property_pointer_type( nullptr );
                 } probe_json_type::space( *context_param, input_param );

                //std::cout << __func__ << " - "<< __LINE__ << " - " << "end" << std::endl;
                return property_pointer_type( pile );
               }

           public:
             template < typename class_name, typename view_name >
              static void register_class( parser_type &  parser_param, context_input_pointer_type &context_param )
               {
                return register__any<class_name>( std::bind( &this_type::template read_class<class_name, view_name>, std::ref(parser_param), context_param, std::placeholders::_1 ), parser_param );
               }

           private:
             template < typename value_name >
              static  property_pointer_type read_vector( parser_type &  parser_param, context_input_pointer_type &context_param, input_type& input_param )
              {  //std::cout << __func__ << " - "<< __LINE__ << std::endl;
               typedef  value_name value_type;
               typedef  std::vector<value_name> vector_type;
               typedef typename ::reflection::property::inspect::pure_class<value_name const&> inspect_type;
               typedef typename ::reflection::property::trinity::simple_struct<vector_type>::typedef_type trinity_type;

                probe_json_type::space( *context_param, input_param );
                if( false == probe_json_type::character( *context_param, input_param, '[' ) )
                 { // TODO input_param.seekg( current_position )
                  return property_pointer_type( nullptr );
                 } probe_json_type::space( *context_param, input_param );

                auto trinity_ptr = new trinity_type;
                vector_type & vector = trinity_ptr->disclose();
                auto trinity_peoperty = property_pointer_type( trinity_ptr );

                while( true )
                 {
                  probe_json_type::space( *context_param, input_param );

                  auto item_property = parser_param.facility().template create<input_type&>( identificator_type::template get<value_type>(), input_param );
                  if( nullptr == item_property )
                   {
                    break;
                   }probe_json_type::space( *context_param, input_param );
                  auto item_inspect = std::dynamic_pointer_cast< inspect_type >( item_property );
                  if( nullptr == item_inspect )
                   {
                    break;
                   }

                  vector.push_back( item_inspect->present() );

                  if( false == probe_json_type::character( *context_param, input_param, ',' ) )
                   {
                     break;
                   } probe_json_type::space( *context_param, input_param );
                 }

                probe_json_type::space( *context_param, input_param );
                if( false == probe_json_type::character( *context_param, input_param, ']' ) )
                 { // TODO input_param.seekg( current_position )
                  return property_pointer_type( nullptr );
                 }

               return trinity_peoperty;
              }

           public:
             template < typename value_name >
              static void register_vector( parser_type &  parser_param, context_input_pointer_type &context_param )
               {
                return register__any< std::vector<value_name> >( std::bind( &read_vector<value_name>, std::ref( parser_param ), context_param, std::placeholders::_1  ) , parser_param );
               }
          };

       }
     }
   }
 }

#endif
