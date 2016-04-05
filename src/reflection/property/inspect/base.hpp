#ifndef reflection_property_inspect_base
#define reflection_property_inspect_base

#include "./_pure.hpp"
#include "../_carrier.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template
       <
         typename image_name
        ,typename storage_name    //= type_name
        ,typename convertor_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
       >
       class base_class
        : virtual public ::reflection::property::inspect::pure_class< image_name >
        , virtual public ::reflection::property::_internal::carrier_class<storage_name>
        {
         public:
           typedef image_name        image_type;
           typedef storage_name    storage_type;
           typedef convertor_name  convertor_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name>  carrier_type;

                     base_class(){ }

            explicit base_class( storage_type   const& carrier_param, convertor_type const& convertor_param = convertor_type() )
              : carrier_type( carrier_param ), m_convertor( convertor_param )
                     {
                     }

         public: 
           image_type present( void )const
            {
             return this->convertor()( this->carrier_type::carrier() );
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
