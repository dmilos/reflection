#ifndef reflection_property_dispatch
#define reflection_property_dispatch

// ::reflection::property::dispatch_class<parameter_name>

#include "./_pure.hpp"
#include "./inspect/_pure.hpp"
#include "./direct/_pure.hpp"
#include "./mutate/_pure.hpp"


namespace reflection
 {
  namespace property
   {
 
    template < typename parameter_name/*&*/, typename report_name = bool >
     class dispatch_class
      {
       public:
         typedef parameter_name parameter_type;

         typedef ::reflection::property::pure_class property_type;
 
         typedef parameter_name & original_type;
         typedef ::reflection::property::direct::pure_class<original_type>  direct_type;

         typedef parameter_name const& model_type;
         typedef ::reflection::property::mutate::pure_class<model_type, report_name>  mutate_type;
       public:
         dispatch_class( property_type & property_instance )
          : m_instance( property_instance )
          {
          }
    
       public:
         bool valid()const
          {
           bool A = ::reflection::property::direct::check<original_type>( m_instance );
           bool B = ::reflection::property::mutate::check<model_type, report_name>( m_instance );
           return A || B;
          }

         bool set( model_type model )
          {
           report_name result = false;
           if( true == ::reflection::property::mutate::check<model_type, report_name>( m_instance ) )
            {
             auto result = ::reflection::property::mutate::process<model_type,report_name>( m_instance, model );
             if( false != result )
              {
               return result;
              }
            }
         
           if( true == ::reflection::property::direct::check<original_type>( m_instance ) )
            {
             ::reflection::property::direct::disclose<original_type>( m_instance ) = model;
             result = true;
            }
         
           return result;
          }
       private:
         property_type & m_instance;
      };
    
    template < typename report_name >
     class dispatch_class< void, report_name >
      {
       public:
         typedef void parameter_type;
    
         typedef report_name  report_type;
    
         typedef ::reflection::property::pure_class property_type;
    
         typedef void original_type;
         typedef ::reflection::property::direct::pure_class<original_type>  direct_type;
 
         typedef void model_type;
         typedef ::reflection::property::mutate::pure_class<model_type, report_name>  mutate_type;
 
       public:
         dispatch_class( property_type & property_instance )
         : m_instance( property_instance )
          {
          }

       public:
         bool valid( )
          {
           bool A = ::reflection::property::direct::check<original_type>( m_instance );
           bool B = ::reflection::property::mutate::check<model_type, report_name>( m_instance );
           return A || B;
          }

       bool set( )
        {
         report_name result = false;
         if( true == ::reflection::property::mutate::check<model_type, report_name>( m_instance ) )
          {
           auto result = ::reflection::property::mutate::process<report_name>( m_instance );
           if( false != result )
            {
             return result;
            }
          }
    
         if( true == ::reflection::property::direct::check<original_type>( m_instance ) )
          {
           ::reflection::property::direct::disclose<original_type>( m_instance );
           result = true;
          }
    
         return result;
        }
       private:
         property_type & m_instance;
     };
    
    template < typename parameter_name, typename report_name >
     class dispatch_class< parameter_name const, report_name >
      {
       public:
         typedef parameter_name const parameter_type;
         typedef parameter_name const& model_type;
    
         typedef report_name  report_type;
    
         typedef ::reflection::property::pure_class property_type;
    
       public:
         dispatch_class( property_type & property_instance )
          {
          }

       public:
         bool valid( )
          {
           return false;
          }
         
         bool set( model_type model )
          {
           return false;
          }
     };
    
    template < typename parameter_name, typename report_name >
     class dispatch_class< parameter_name const&, report_name >
      {
       public:
         typedef report_name  report_type;
         typedef parameter_name const& parameter_type;
         typedef parameter_name const& model_type;

         typedef ::reflection::property::pure_class property_type;

       public:
         dispatch_class( property_type & property_instance )
          {
          }

       public:
         bool valid(  )
          {
           return false;
          }

         bool set( model_type model )
          {
           return false;
          }
     };
    
   }
 }

#endif
