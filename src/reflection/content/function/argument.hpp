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

           typedef ::reflection::property::pure_class                                 property_type;
           typedef property_type *                                            property_pointer_type;
           typedef ::reflection::ornament::category_class<identifier_type>            category_type;

           typedef std::vector< property_pointer_type  > container_type;

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
              if( category_instance->identifier() != signature_param[index].instance() )
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
