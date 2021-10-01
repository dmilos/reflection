#ifndef reflection_operation_factory_facility
#define reflection_operation_factory_facility

// ::reflection::operation::factory_class<identifier_name,report_name>

#include "../../content/trinity/simple.hpp"
#include "../../utility/function/_pure.hpp"

//#include "../../../content/function/algorithm.hpp"
//#include "../../../content/typedef/typedef.hpp"
//#include "../../../content/enum/enum.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace factory
     {

      template
       <
         typename  identifier_name = std::string
        ,typename      report_name = bool
        //,template <typename> class pointer_name  = std::shared_ptr
        //,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct facility_class
        {
         public:
           typedef  identifier_name    identifier_type;
           typedef      report_name        report_type;


           typedef ::reflection::property::pure_class          property_type;
           typedef  std::shared_ptr<property_type>             property_pointer_type;

           typedef  ::reflection::utility::function::pure_class< property_pointer_type >  constructor_type;
           typedef  std::shared_ptr<constructor_type>                                     constructor_pointer_type;

           typedef std::map<identifier_type, constructor_pointer_type > container_type;

         public:
           typedef ::reflection::operation::factory::facility_class<identifier_type, report_name > this_type;

           typedef ::reflection::ornament::category_class<identifier_type>            category_type;


           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

         public:

         public:
           facility_class( )
            {
             {
              typedef ::reflection::utility::function::static_class<this_type::property_pointer_type>  static_type;
              this->insert( identificator_type::NAT(), constructor_pointer_type{  new  static_type{ &this_type::constructor_nullptr } } );
             }

             this->register_data<bool>();

             this->register_data<std::int8_t>();
             this->register_data<std::int16_t>();  this->register_data<std::int32_t>();  this->register_data<std::int64_t>();

             this->register_data<std::uint8_t>();
             this->register_data<std::uint16_t>(); this->register_data<std::uint32_t>(); this->register_data<std::uint64_t>();

             this->register_data<char>();      this->register_data< unsigned char>();
             this->register_data<wchar_t>();

             this->register_data<short>();     this->register_data< unsigned short     >();
             this->register_data<int>();       this->register_data< unsigned           >();
             this->register_data<long>();      this->register_data< unsigned long      >();
             this->register_data<long long>(); this->register_data< unsigned long long >();

             this->register_data<void*>();
             this->register_data<nullptr_t>();

             this->register_data<std::string>(); this->register_data<std::wstring>();

             this->register_data< std::vector< int > >();
             this->register_data< std::map< int, int > >();
            }

         private:
           container_type m_container;

         public:
           void clear()
            {
             m_container.clear();
            }

         public:
           constructor_type const& find( identifier_type const& identifier_param )const
            {
             auto iterator = this->m_container.find( identifier_param );
             if( iterator == this->m_container.end() )
              {
               return this->find( identificator_type::NAT() );
              }
             return *iterator->second.get();
            }

         public:
           void insert( identifier_type const& identifier_param, constructor_pointer_type const& constructor_pram )
            {
             this->m_container.emplace( identifier_param, constructor_pram );
             this->m_container[ identifier_param ] = constructor_pram ;
            }

           template< typename data_name >
            void insert( constructor_pointer_type const& constructor_pram )
             {
              identifier_type i = identificator_type::template get< data_name >();
              this->m_container[i] = constructor_pram ;
             }

         public:
           property_pointer_type create( identifier_type const& identifier_param )const
            {
             auto const& constructor = this->find( identifier_param );
             return constructor.execute();
            }

           template< typename first_name >
            property_pointer_type create( identifier_type const& identifier_param, first_name && first_param )const
             {
              auto const& constructor = this->find( identifier_param );

              typedef ::reflection::utility::function::pure_class<property_pointer_type, first_name> constructor_type;

              auto real = dynamic_cast< constructor_type const*>( &constructor );
              if( nullptr == real )
               {
                return property_pointer_type( nullptr );
               }
              return real->execute( std::forward<first_name>( first_param ) );
             }

           //template< typename first_name, typename second_name >
           // property_pointer_type create( identifier_type const& identifier_param, first_name && first_param, second_name && second_param )const
           //{
           // auto const& constructor = this->find( identifier_param );
           //
           // typedef ::reflection::utility::function::pure_class<property_pointer_type, first_name, second_name> constructor_type;
           //
           // auto real = dynamic_cast< constructor_type const*>( &constructor );
           // if( nullptr == real )
           //  {
           //   return nullptr;
           //  }
           // return real->execute( std::forward<first_name>( first_param ), std::forward<second_name>( second_param ) );
           //}
           //
           //template< typename data_name >
           // property_pointer_type create()const
           //  {
           //   return this->create( identificator_type::template get< data_name >() );
           //  }
           //
           //template< typename data_name, typename first_name >
           // property_pointer_type create( first_name && first_param )const
           //  {
           //   return this->create( identificator_type::template get< data_name >(), std::forward<first_name>( first_param ) );
           //  }
           //
           //template< typename data_name, typename first_name, typename second_name  >
           // property_pointer_type create( first_name && first_param, second_name && second_param )const
           //  {
           //   return this->create( identificator_type::template get< data_name >(), std::forward<first_name>( first_param ), std::forward<second_name>( second_param ) );
           //  }

         public:
           template< typename data_name >
            static property_pointer_type constructor_simple()
             {
              typedef typename ::reflection::content::trinity::simple_struct<identifier_type,data_name>::typedef_type trinity_type;
              property_type *raw = new trinity_type{};
              this_type::property_pointer_type result;
              result.reset( raw );
              return result;
             }

           static property_pointer_type constructor_nullptr()
            {
             return nullptr;
            }

        public:
          template< typename data_name >
           void register_data()
            {
             typedef ::reflection::utility::function::static_class<this_type::property_pointer_type>  static_type;
             auto m = constructor_pointer_type{ new static_type{ &this_type::constructor_simple<data_name>  } };

             this->template insert< data_name >( m );
            }
       };

     }
   }
 }

#endif
