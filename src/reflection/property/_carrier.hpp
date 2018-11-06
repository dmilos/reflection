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

        public:
          explicit carrier_class( storage_type const& storage_param = storage_type() )
           : m_storage( storage_param )
           {
           }

          virtual ~carrier_class(){}

        public:
          storage_type   const&  storage ( void )const
           {
            return m_storage;
           }
          virtual void                   storage( storage_type const& storage_param )
           {
            m_storage = storage_param;
           }

        protected:
          storage_type&          storage()
           {
            return m_storage;
           }

        private:
          storage_type         m_storage;
       };

     };

   }
 }

 #endif



