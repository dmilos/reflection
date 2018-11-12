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
        ,typename retriever_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
       >
       class basic_class
        : virtual public ::reflection::property::inspect::pure_class< image_name >
        , virtual public ::reflection::property::_internal::carrier_class<storage_name>
        {
         public:
           typedef image_name        image_type;
           typedef storage_name    storage_type;
           typedef retriever_name  retriever_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name>  carrier_type;

            explicit basic_class
             (
              retriever_type const& retriever_param = retriever_type()
             )
             : m_retriever( retriever_param )
             {
             }

            explicit basic_class
             (
               storage_type   const& storage_param
              ,retriever_type const& retriever_param = retriever_type()
             )
             : m_retriever( retriever_param )
             {
              this->storage( storage_param );
             }

         public:
           image_type present( void )const
            {
             return this->retriever()( this->carrier_type::storage() );
            }

         public:
           retriever_type const&   retriever()const{ return m_retriever; }
           void                 retriever( retriever_type const& retriever_param ){ m_retriever = retriever_param; }
         //retriever_type   &   retriever(){ return m_retriever; }
         protected:
           retriever_type      &   F1_retriever(){ return m_retriever; }
         private:
           retriever_type          m_retriever;

        };

      }
    }
  }

#endif
