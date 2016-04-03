#ifndef reflection_property_direct_base
#define reflection_property_direct_base

#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      template
       <
         typename original_name   //!< mutablize before use!
        ,typename carrier_name    //= type_name
        ,typename extractor_name  //= stl_ext::identity_cast<  type_name const&, carrier_name const& >
       >
       class base_class
        : virtual public ::reflection::property::direct::pure_class< original_name >
        {
         public:
           typedef original_name   original_type;
           typedef carrier_name    carrier_type;
           typedef extractor_name  extractor_type;

                     base_class(){ }

            explicit base_class( carrier_type   const& carrier_param, extractor_type const& extractor_param = extractor_type() )
              : m_carrier( carrier_param ), m_extractor( extractor_param )
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
           original_type get( void )
            {
             return F1_extractor()( F1_carrier() );
            }

         public: 
           extractor_type const&   extractor()const{ return m_extractor; }
           void                 extractor( extractor_type const& extractor_param ){ m_extractor = extractor_param; }
         //extractor_type   &   extractor(){ return m_extractor; }
         protected:
           extractor_type      &   F1_extractor(){ return m_extractor; }
         private:
           extractor_type          m_extractor;

        };

      }
    }
  }

#endif
