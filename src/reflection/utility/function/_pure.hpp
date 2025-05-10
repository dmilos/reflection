#ifndef reflection_utility_function_pure
#define reflection_utility_function_pure

// ::reflection::utility::function::pure_class<return_name,...>


namespace reflection
 {
  namespace utility
   {
    namespace function
     {

      template
       <
         typename return_name
        ,typename ... argument_name
        >
       class pure_class
        {
         public:
           typedef return_name    return_type;
         //typedef argument_name...     argument_type...;

         public:
                    pure_class(){}
           virtual ~pure_class(){}

         public:
           virtual return_name execute( argument_name ... )const=0;
         //virtual return_name execute( argument_name ... )=0;
        };

      template
       <
         typename return_name
        ,typename first_name
       >
       class pure_class<return_name, first_name >
        {
         public:
           typedef return_name    return_type;
           typedef first_name      first_type;

         public:
                    pure_class(){}
           virtual ~pure_class(){}

         public:
           virtual return_name execute( first_name f )const=0;
         //virtual return_name execute( first_name f )const=0;
        };

      template
       <
         typename return_name
       >
       class pure_class<return_name >
        {
         public:
           typedef return_name    return_type;

         public:
                    pure_class(){}
           virtual ~pure_class(){}

         public:
           virtual return_name execute( void )const=0;
         //virtual return_name execute( void )const=0;
        };

     }
   }
 }

#endif
