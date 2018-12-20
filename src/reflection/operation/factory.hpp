#ifndef reflection_operation_transfer_factory
#define reflection_operation_transfer_factory

// ::reflection::operation::transfer::factory_class<identifier_name,report_name>

#include "../content/trinity/simple.hpp"

//#include "../../../content/function/algorithm.hpp"
//#include "../../../content/typedef/typedef.hpp"
//#include "../../../content/enum/enum.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

        template
         <
           typename  identifier_name = std::string
          ,typename      report_name = bool
          //,template <typename> class pointer_name  = std::shared_ptr
          //,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct factory_class
          {
           public:
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

             typedef ::reflection::property::pure_class                                 property_type;
             //typedef pointer_name< property_type > pointer_type;

             typedef  std::shared_ptr< property_type> pointer_type;
             typedef  std::function < pointer_type ( ) > constructor_type;
           //typedef  std::optional<constructor_type> constructor_optional_type;

             //typedef container_name<identifier_type, constructor_type > container_type;
             typedef std::map<identifier_type, constructor_type > container_type;

           public:
             typedef ::reflection::operation::transfer::factory_class<identifier_type, report_name > this_type;

             typedef ::reflection::ornament::category_class<identifier_type>            category_type;


             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           public:
             //typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>              enumeration_type;
             //typedef ::reflection::content::function::algorithm_class<identifier_type>                         algorithm_type;
             //typedef ::reflection::property::typedefinition::pure_class< identifier_type >                typedefinition_type;
             //typedef ::reflection::property::frienddeclaration::pure_class< identifier_type >          frienddeclaration_type;

           public:
             factory_class( )
              {
               this->insert( identificator_type::NAT(), [](){ return pointer_type{}; } );

               this->register_data<std::int8_t>();   this->register_data<std::int16_t>();  this->register_data<std::int32_t>();  this->register_data<std::int64_t>();
               this->register_data<std::uint8_t>();  this->register_data<std::uint16_t>(); this->register_data<std::uint32_t>(); this->register_data<std::uint64_t>();

               this->register_data<void*>();
               this->register_data<std::string>(); this->register_data<std::wstring>();

               this->register_data<char>();      this->register_data< unsigned char>(); 
               this->register_data<wchar_t>();  
               this->register_data<short>();     this->register_data< unsigned short>();
               this->register_data<int>();       this->register_data< unsigned>();
               this->register_data<long>();      this->register_data< unsigned long>();
               this->register_data<long long>(); this->register_data< unsigned long long>();

               this->register_data<nullptr_t>();

               this->register_data<std::vector< int > >();
               this->register_data<std::map< int, int > >();

               //observe_param.insert( identificator_type::template get<       enumeration_type  >(), &this_type::enumeration       );
               //observe_param.insert( identificator_type::template get<         algorithm_type  >(), &this_type::function          );
               //observe_param.insert( identificator_type::template get<    typedefinition_type  >(), &this_type::typedefinition    );
               //observe_param.insert( identificator_type::template get< frienddeclaration_type  >(), &this_type::frienddeclaration );
              }

           public:
            pointer_type create( identifier_type const& identifier_param )
             {
              constructor_type constructor_item = this->find( identifier_param );
              return constructor_item();
             }
            template< typename data_name >
             pointer_type create(  )
              {
               return this->create( identificator_type::template get< data_name >() );
              }


           public:
             container_type m_container;

             constructor_type & find( identifier_type const& identifier_param )
              {
               auto iterator = this->m_container.find( identifier_param );
               if( iterator == this->m_container.end() )
                {
                 return find( identificator_type::NAT() );
                }
               return iterator->second;
              }

             void insert( identifier_type const& identifier_param, constructor_type const& constructor_pram )
              {
               this->m_container.emplace( identifier_param, constructor_pram );
              }

           public:
             template< typename data_name >
              void register_pointer()
               {
                auto             i = identificator_type::template get<data_name*>();
                constructor_type c =  &this_type::construct_data<data_name*> ;
                this->insert( i, c );
               }

           private:
             template< typename data_name >
              static pointer_type construct_data()
               {
                typedef typename ::reflection::content::trinity::simple_struct<identifier_type,data_name>::typedef_type trinity_type;
                property_type *raw = new trinity_type{};
                this_type::pointer_type result;
                result.reset( raw );
                return result;
               }

          public:
            template< typename data_name >
             void register_data()
              {
               auto             i = identificator_type::template get<data_name>();
               constructor_type c =  &this_type::construct_data<data_name> ;
               this->insert( i, c );
              }

         };

     }
   }
 }

#endif
