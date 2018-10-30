#ifndef reflection_operation_output
#define reflection_operation_output

// ::reflection::operation::output


namespace reflection
 {
  namespace operation
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
       class base_class : virtual public ::reflection::operation::pure_class
        {
         public:
           typedef key_name key_type;
           typedef ::reflection::property::pure_class  property_type;
           pure_class( )
            {
            }

           virtual ~pure_class()
            {
            }
         public:
          using pure_type::send;
          virtual pure_class& base_class::send( key_type const& k, property_type const& p )const=0;
        };

     }
   }
 }

#endif
