#ifndef reflection_property_inspect_base
#define reflection_property_inspect_base

#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template
       <
         typename image_name   //!< mutablize before use!
        ,typename carrier_name    //= type_name
        ,typename convertor_name  //= stl_ext::identity_cast<  type_name const&, carrier_name const& >
       >
       class base_class
        : virtual public ::reflection::property::inspect::pure_class< image_name >
        {
         public:
           typedef image_name        image_type;
           typedef carrier_name    carrier_type;
           typedef convertor_name  convertor_type;

                     base_class(){ }

            explicit base_class( carrier_type   const& carrier_param, convertor_type const& convertor_param = convertor_type() )
              : m_carrier( carrier_param ), m_convertor( convertor_param )
                     {
                     }

         public:
           carrier_type   const&  carrier ( void )const
            {
             return m_carrier; 
            }
           void                carrier( carrier_type const& carrier_param )
            {
             m_carrier = carrier_param;  
            }
         protected:
           carrier_type&          F1_carrier()
            {
             return m_carrier; 
            }
         private:
           carrier_type           m_carrier;

         public: 
           image_type get( void )const
            {
             return convertor()( carrier() );
            }

         public: 
           convertor_type const&   convertor()const{ return m_convertor; }
           void                 convertor( convertor_type const& convertor_param ){ m_convertor = convertor_param; }
         //convertor_type   &   convertor(){ return m_convertor; }
         protected:
           convertor_type      &   F1_convertor(){ return m_convertor; }
         private:
           convertor_type          m_convertor;

        };

      }
    }
  }

#endif
