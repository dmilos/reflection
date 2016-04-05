#ifndef reflection_property_direct_base
#define reflection_property_direct_base

#include "./_pure.hpp"
#include "../_carrier.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      template
       <
         typename original_name
        ,typename storage_name    //= type_name
        ,typename extractor_name  //= stl_ext::identity_cast<  type_name const&, carrier_name const& >
       >
       class base_class
        : virtual public ::reflection::property::direct::pure_class< original_name >
        , virtual public ::reflection::property::_internal::carrier_class<storage_name>
        {
         public:
           typedef original_name   original_type;
           typedef storage_name    storage_type;
           typedef extractor_name  extractor_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

                     base_class(){ }

            explicit base_class( storage_type   const& storage_param, extractor_type const& extractor_param = extractor_type() )
              : carrier_type( storage_param ), m_extractor( extractor_param )
              {
              }

         public: 
           original_type disclose( void )
            {
             return this->F1_extractor()( this->carrier_type::F1_carrier() );
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
