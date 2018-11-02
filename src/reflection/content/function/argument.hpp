#ifndef reflection_content_function_argument
#define reflection_content_function_argument

// ::reflection::content::function::argument_class<identificator_name>


namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
        typename identifier_name
       >
       class argument_struct
        {
         public:
           typedef identifier_name identifier_type;

           typedef ::reflection::property::pure_class                            propert_type;
           typedef ::reflection::content::category::pure_class<identifier_type> category_type;

           typedef std::vector<  propert_type * > container_type, parameter_type;

           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;

         public:

          static bool check( container_type const& args_param, signature_type const& signature_param )
           {
            if( args_param.size() != signature_param.size() )
             {
              return false;
             }

            for( std::size_t index=0; index < args_param.size(); ++index )
             {
              category_type const* category_instance = dynamic_cast< category_type const*>( args_param[index] );
              if( nullptr == category_instance )
               {
                return false;
               }
              if( category_instance->identifier() != signature_param[index] )
               {
                return false;
               }
             }

            return true;
           }

        };

     }
   }
 }

#endif
