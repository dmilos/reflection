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

           typedef ::reflection::property::pure_class                               propert_type;
           typedef ::reflection::content::category::pure_class<identifier_type> category_type;

           typedef std::vector<  propert_type * > typedef_type;

           typedef typename ::reflection::content::function::signature_struct<identifier_type>::typedef_type   signature_type;

          static bool check( typedef_type const& args_param, signature_type const& signature_param )
           {
            if( args_param.size() != signature_param.size() )
             {
              return false;
             }

            for( std::size_t index; index < args_param.size(); ++index )
             {
              category_type const* c = dynamic_cast< category_type const*>( args_param[index] );
              if( nullptr == c )
               {
                return false;
               }
              if( c->identifier() != signature_param[index].identifierr() )
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
