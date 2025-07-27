#ifndef reflection_property_retrieve
#define reflection_property_retrieve

// ::reflection::content::function::retrieve_class<parameter_name>

#include "./_pure.hpp"
#include "./inspect/_pure.hpp"
#include "./direct/_pure.hpp"
#include "./mutate/_pure.hpp"


namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template< typename parameter_name >
       class retrieve_class
        {
         public:
           typedef parameter_name parameter_type;

           typedef ::reflection::property::pure_class property_type;

           typedef parameter_name & original_type;
           typedef ::reflection::property::direct::pure_class<original_type>  direct_type;

           typedef parameter_name const& image_type;
           typedef ::reflection::property::inspect::pure_class<image_type>  inspect_type;

         public:
           retrieve_class( property_type & property_instance )
            {
             ::reflection::property::variable::unpack<original_type,image_type>( property_instance, &m_director, &m_inspector );
            }

         public:
           bool valid()const
            {
             return ( nullptr != m_inspector ) || ( nullptr != m_director );
            }

           parameter_type get( )const
            {
             if( nullptr != m_inspector )
              {
               return m_inspector->present();
              }

             if( nullptr != m_director)
              {
               return m_director->disclose();
              }
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           inspect_type  *m_inspector;
           direct_type   *m_director;
        };

      template<  >
       struct retrieve_class< void >
        {
         public:
           typedef void parameter_type;

           typedef ::reflection::property::pure_class property_type;

           typedef void original_type;
           typedef ::reflection::property::direct::pure_class<original_type>  direct_type;

           typedef void image_type;
           typedef ::reflection::property::inspect::pure_class<image_type>  inspect_type;

         public:
           retrieve_class( property_type & property_instance )
            {
             ::reflection::property::variable::unpack<original_type,image_type>( property_instance, &m_director, &m_inspector );
            }

         public:
           bool valid()const
            {
             return ( nullptr != m_inspector ) || ( nullptr != m_director );
            }

           parameter_type get( )const
            {
             if( nullptr != m_inspector )
              {
               return m_inspector->present();
              }

             if( nullptr != m_director )
              {
               return m_director->disclose();
              }
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           inspect_type  *m_inspector;
           direct_type   *m_director;
        };

      template< typename parameter_name >
       struct retrieve_class< parameter_name const >
        {
         public:
           typedef parameter_name const parameter_type;

           typedef ::reflection::property::pure_class property_type;

           typedef parameter_name const& image_type;
           typedef ::reflection::property::inspect::pure_class<image_type>  inspect_type;

         public:
           retrieve_class( property_type & property_instance )
            {
             m_inspector = dynamic_cast<inspect_type *>( &property_instance );
            }

         public:
           bool valid()const
            {
             return ( nullptr != m_inspector );
            }

           parameter_type get( )const
            {
             if( nullptr != m_inspector )
              {
               return m_inspector->present();
              }
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           inspect_type  *m_inspector;
        };

      template< typename parameter_name >
       struct retrieve_class< parameter_name const& >
        {
         public:
           typedef parameter_name const&  parameter_type;

           typedef ::reflection::property::pure_class property_type;

           typedef parameter_name const& image_type;
           typedef ::reflection::property::inspect::pure_class<image_type>  inspect_type;

         public:
           retrieve_class( property_type & property_instance )
            {
             m_inspector = dynamic_cast<inspect_type *>( &property_instance );
            }

         public:
           bool valid()const
            {
             return ( nullptr != m_inspector );
            }

           parameter_type get( )const
            {
             if( nullptr != m_inspector )
              {
               return m_inspector->present();
              }

             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           inspect_type  *m_inspector;
        };

      template< typename parameter_name >
       struct retrieve_class< parameter_name & >
        {
         public:
           typedef parameter_name & parameter_type;

           typedef ::reflection::property::pure_class property_type;

           typedef parameter_name & original_type;
           typedef ::reflection::property::direct::pure_class<original_type>  direct_type;

         public:
           retrieve_class( property_type & property_instance )
            {
             m_director = dynamic_cast<direct_type*>( &property_instance );
            }

         public:
           bool valid()const
            {
             return ( nullptr != m_director );
            }

           parameter_type get( )const
            {
             if( nullptr != m_director)
              {
               return m_director->disclose();
              }
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           direct_type   *m_director;
        };

     }
   }
 }

#endif
