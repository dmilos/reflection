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

      template < typename parameter_name >
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
           : m_instance( property_instance )
            {
            }

         public:
           bool valid()const
            {
             bool A = ::reflection::property::direct::check<original_type>( m_instance );
             bool B = ::reflection::property::inspect::check<image_type>( m_instance );
             return A || B;
            }

           parameter_type get( )const
            {
             if( true == ::reflection::property::inspect::check<image_type>( m_instance ) )
              {
               return ::reflection::property::inspect::present<image_type>( m_instance );
              }
           
             if( true == ::reflection::property::direct::check<original_type>( m_instance ) )
              {
               return ::reflection::property::direct::disclose<original_type>( m_instance );
              }
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           property_type &m_instance;
        };

      template <  >
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
           : m_instance( property_instance )
            {
            }

         public:
           bool valid()const
            {
             bool A = ::reflection::property::direct::check<original_type>( m_instance );
             bool B = ::reflection::property::inspect::check< image_type>( m_instance );
             return A || B;
            }

           parameter_type get( )const
            {
             if( true == ::reflection::property::inspect::check<image_type>( m_instance ) )
              {
               return ::reflection::property::inspect::present<image_type>( m_instance );
              }
           
             if( true == ::reflection::property::direct::check<original_type>( m_instance ) )
              {
               return ::reflection::property::direct::disclose<original_type>( m_instance );
              }
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           property_type &m_instance;
        };

      template < typename parameter_name >
       struct retrieve_class< parameter_name const >
        {
         public:
           typedef parameter_name const parameter_type;

           typedef ::reflection::property::pure_class property_type;
           
           typedef parameter_name const& image_type;
           typedef ::reflection::property::inspect::pure_class<image_type>  inspect_type;
           
         public:
           retrieve_class( property_type & property_instance )
           : m_instance( property_instance )
            {
            }

         public:
           bool valid()const
            {
             bool B = ::reflection::property::inspect::check<image_type>( m_instance );
             return B;
            }

           parameter_type get( )const
            {
             if( true == ::reflection::property::inspect::check<image_type>( m_instance ) )
              {
               return ::reflection::property::inspect::present<image_type>( m_instance );
              }
           
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           property_type &m_instance;
        };

      template < typename parameter_name >
       struct retrieve_class< parameter_name const& >
        {
         public:
           typedef parameter_name const&  parameter_type;
           
           typedef ::reflection::property::pure_class property_type;
           
           typedef parameter_name const& image_type;
           typedef ::reflection::property::inspect::pure_class<image_type>  inspect_type;
           
         public:
           retrieve_class( property_type & property_instance )
           : m_instance( property_instance )
            {
            }

         public:
           bool valid()const
            {
             bool B = ::reflection::property::inspect::check<image_type>( m_instance );
             return B;
            }

           parameter_type get( )const
            {
             if( true == ::reflection::property::inspect::check<image_type>( m_instance ) )
              {
               return ::reflection::property::inspect::present<image_type>( m_instance );
              }
           
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           property_type &m_instance;
        };

      template < typename parameter_name >
       struct retrieve_class< parameter_name & >
        {
         public:
           typedef parameter_name & parameter_type;
           
           typedef ::reflection::property::pure_class property_type;
           
           typedef parameter_name & original_type;
           typedef ::reflection::property::direct::pure_class<original_type>  direct_type;

         public:
           retrieve_class( property_type & property_instance )
           : m_instance( property_instance )
            {
            }

         public:
           bool valid()const
            {
             bool A = ::reflection::property::direct::check<original_type>( m_instance );
             return A ;
            }

           parameter_type get( )const
            {
             if( true == ::reflection::property::direct::check<original_type>( m_instance ) )
              {
               return ::reflection::property::direct::disclose<original_type>( m_instance );
              }
             throw "Unable to retrieve data. Use check before!!!";
            }
         public:
           property_type &m_instance;
        };

     }
   }
 }

#endif
