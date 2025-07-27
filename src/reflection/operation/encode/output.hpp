#ifndef reflection_operation_encode_output
#define reflection_operation_encode_output

// ::reflection::operation::output::pure_class


namespace reflection
 {
  namespace operation
   {
    namespace encode
     {
      namespace output
       {

        class pure_class
         {
          public:
            typedef ::reflection::property::pure_class  property_type;
            pure_class( )
             {
             }

            virtual ~pure_class()
             {
             }
          public:
           virtual pure_class& send( property_type  const& p )const=0;
         };


        template
         <
           typename key_name
         >
         class base_class 
          : virtual public ::reflection::operation::encode::output::pure_class
          {
           public:
             typedef key_name key_type;
             typedef ::reflection::operation::encode::output::pure_class  pure_type;
             typedef ::reflection::property::pure_class  property_type;
             base_class( )
              {
              }

             virtual ~base_class()
              {
              }
           public:
            using pure_type::send;
            virtual pure_class& send( key_type const& data, property_type const& p )const=0;
          };

       }
     }
   }
 }

#endif
