#ifndef reflection_property__internal_carrier
#define reflection_property__internal_carrier

// ::reflection::property::_internal::carrier::pure_class
// ::reflection::property::_internal::carrier::wrapper_class<storage_name>
// ::reflection::property::_internal::proxy_class<storage_name>

namespace reflection
 {
  namespace  property
   {
    namespace _internal
     {
      namespace carrier
       {

        class pure_class
         {
          public:
                     pure_class(){}
            virtual ~pure_class(){}
          public:
            virtual bool valid()const{ return true; }
         };

        template
         <
           typename storage_name
         >
         class wrapper_class
          {
           public:
             typedef storage_name storage_type;

           public:
             explicit wrapper_class( storage_type const& storage_param = storage_type{})
              : m_storage( storage_param )
              {
              }
             virtual ~wrapper_class(){}

           public:
             virtual bool valid()const
              {
               return true;
              }

           public:
             storage_type   const&  storage( void )const
              {
               return this->m_storage;
              }
             virtual void           storage( storage_type const& storage_param )
              {
               this->m_storage = storage_param;
              }

           protected:
             storage_type&          storage( void )
              {
               return this->m_storage;
              }

           private:
             storage_type         m_storage;
          };

        template
         <
           typename storage_name
         >
         class wrapper_class<storage_name*>
          {
           public:
             typedef storage_name* storage_type;

           public:
             explicit wrapper_class( storage_type const& storage_param = nullptr )
              : m_storage( storage_param )
              {
              }
             virtual ~wrapper_class(){}

           public:
              virtual bool valid()const
               {
                return nullptr != m_storage;
               }

           public:
             storage_type   const&  storage( void )const
              {
               return this->m_storage;
              }
             virtual void           storage( storage_type const& storage_param )
              {
               this->m_storage = storage_param;
              }

           protected:
             storage_type&          storage( void )
              {
               return this->m_storage;
              }

           private:
             storage_type         m_storage;
          };
 
        template
         <
           typename storage_name
         >
         class wrapper_class<storage_name&>
          {
           public:
             typedef storage_name& storage_type;

           public:
             explicit wrapper_class( storage_type & storage_param )
              : m_storage( storage_param )
              {
              }
             virtual ~wrapper_class(){}

           public:
              virtual bool valid()const
               {
                return true;
               }

           public:
             storage_type   const&  storage( void )const
              {
               return this->m_storage;
              }

           protected:
             storage_type&          storage( void )
              {
               return this->m_storage;
              }

           private:
             storage_type         m_storage;
          };

       }

      template
       <
        typename storage_name
       >
      class proxy_class
       : public  ::reflection::property::_internal::carrier::pure_class
       , public  ::reflection::property::_internal::carrier::wrapper_class<storage_name>
       {
        public:
          typedef  ::reflection::property::_internal::carrier::pure_class  pure_class;
          typedef  ::reflection::property::_internal::carrier::wrapper_class<storage_name>    wrapper_type;

        public:
          using wrapper_type::wrapper_type;
          using wrapper_type::storage;

        public:
          virtual bool valid()const
           {
            return this->pure_class::valid() && this->wrapper_type::valid();
           }
       };

     }
   }
 }

 #endif
