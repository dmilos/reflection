#ifndef reflection_property__internal_carrier
#define reflection_property__internal_carrier
// ::reflection::property::_internal::carrier_class<storage_name>

namespace reflection
 {
  namespace  property
   {
    namespace _internal
     {

      template
       <
        typename storage_name
       >
      class carrier_class
       {
        public:
          typedef storage_name storage_type;

          explicit carrier_class( storage_type const& storage_param )
           : m_storage( storage_param )
           {

           }

         public:
           storage_type   const&  carrier ( void )const
            {
             return m_storage; 
            }
           void                carrier( storage_type const& storage_param )
            {
             m_storage = storage_param;  
            }

         protected:
           storage_type&          F1_carrier()
            {
             return m_storage; 
            }
         private:
           storage_type           m_storage;
       };

     };

   }
 }

 #endif



