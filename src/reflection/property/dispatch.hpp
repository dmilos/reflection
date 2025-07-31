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
          {
           ::reflection::property::exposed::unpack/*< original_type, model_type, report_name >*/(property_instance, &m_director, &m_mutator);
          }

       public:
         bool valid()const
          {
           return ( nullptr != m_director ) || ( nullptr != m_mutator );
          }

         bool set( model_type model )
          {
           return ::reflection::property::exposed::dispatch<original_type, model_type/*, report_name*/>( m_director, m_mutator, model );
          }
       private:
         direct_type   * m_director;
         mutate_type   * m_mutator;
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
          {
           ::reflection::property::exposed::unpack/*< original_type, model_type, report_name >*/(property_instance, &m_director, &m_mutator);
          }

       public:
         bool valid( )
          {
           return ( nullptr != m_director ) || ( nullptr != m_mutator );
          }

         bool set( )
          {
           return ::reflection::property::exposed::dispatch/*<original_type, model_type, report_name>*/( m_director, m_mutator );
          }
       private:
         direct_type   *m_director;
         mutate_type   *m_mutator;
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
