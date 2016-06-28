#ifndef reflection_content_function_pure_hpp
 #define reflection_content_function_pure_hpp
 // ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>

 #include "../../type/string.hpp"
 #include "../../property/function/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename return_name
        ,typename first_name
        ,typename second_name
        ,typename third_name
        ,typename fourth_name
        ,typename fifth_name
        >
       class pure_class
        : virtual public ::reflection::content::pure_class< return_name (first_name,second_name,third_name,fourth_name,fifth_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef ::reflection::content::pure_class< return_name (first_name,second_name,third_name,fourth_name,fifth_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>   property_type;

           typedef std::array< ::reflection::type::string_type, 6 >   signature_type;

         public:
           pure_class()
            {
             m_signature[0] = typeid( return_name ).name();
             m_signature[1] = typeid(  first_name ).name();
             m_signature[2] = typeid( second_name ).name();
             m_signature[3] = typeid(  third_name ).name();
             m_signature[4] = typeid( fourth_name ).name();
             m_signature[5] = typeid(  fifth_name ).name();
            }

         public:
           using property_type::execute;

         public:
           signature_type const& signature()const{ return m_signature; }
         protected:
           signature_type m_signature;
        };


      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name>
       class pure_class< return_name, first_name, second_name, third_name, fourth_name,void>
        : virtual public ::reflection::content::pure_class< return_name (first_name,second_name,third_name,fourth_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef ::reflection::content::pure_class< return_name (first_name,second_name,third_name,fourth_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>   property_type;

           typedef std::array< ::reflection::type::string_type, 6 >   signature_type;

         public:
           pure_class()
            {
             m_signature[0] = typeid( return_name ).name();
             m_signature[1] = typeid(  first_name ).name();
             m_signature[2] = typeid( second_name ).name();
             m_signature[3] = typeid(  third_name ).name();
             m_signature[4] = typeid( fourth_name ).name();
             m_signature[5] = typeid(  void ).name();
            }

         public:
           using property_type::execute;

         public:
           signature_type const& signature()const{ return m_signature; }
         protected:
           signature_type m_signature;
        };

      template< typename return_name, typename first_name, typename second_name, typename third_name>
      class pure_class< return_name, first_name, second_name, third_name, void,void>
        : virtual public ::reflection::content::pure_class< return_name (first_name,second_name,third_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::content::pure_class< return_name (first_name,second_name,third_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>   property_type;

           typedef std::array< ::reflection::type::string_type, 6 >   signature_type;

         public:
           pure_class()
            {
             m_signature[0] = typeid( return_name ).name();
             m_signature[1] = typeid(  first_name ).name();
             m_signature[2] = typeid( second_name ).name();
             m_signature[3] = typeid(  third_name ).name();
             m_signature[4] = typeid( void ).name();
             m_signature[5] = typeid(  void ).name();
            }

         public:
           using property_type::execute;

         public:
           signature_type const& signature()const{ return m_signature; }
         protected:
           signature_type m_signature;
        };

      template< typename return_name, typename first_name, typename second_name>
      class pure_class< return_name, first_name, second_name, void, void,void>
        : virtual public ::reflection::content::pure_class< return_name (first_name,second_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::content::pure_class< return_name (first_name,second_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>   property_type;

           typedef std::array< ::reflection::type::string_type, 6 >   signature_type;

         public:
           pure_class()
            {
             m_signature[0] = typeid( return_name ).name();
             m_signature[1] = typeid(  first_name ).name();
             m_signature[2] = typeid( second_name ).name();
             m_signature[3] = typeid(  void ).name();
             m_signature[4] = typeid(  void ).name();
             m_signature[5] = typeid(  void ).name();
            }

         public:
           using property_type::execute;

         public:
           signature_type const& signature()const{ return m_signature; }
         protected:
           signature_type m_signature;
        };

      template< typename return_name, typename first_name>
      class pure_class< return_name, first_name, void, void, void,void>
        : virtual public ::reflection::content::pure_class< return_name (first_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::content::pure_class< return_name (first_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>   property_type;

           typedef std::array< ::reflection::type::string_type, 6 >   signature_type;

         public:
           pure_class()
            {
             m_signature[0] = typeid( return_name ).name();
             m_signature[1] = typeid(  first_name ).name();
             m_signature[2] = typeid(  void ).name();
             m_signature[3] = typeid(  void ).name();
             m_signature[4] = typeid(  void ).name();
             m_signature[5] = typeid(  void ).name();
            }

         public:
           using property_type::execute;

         public:
           signature_type const& signature()const{ return m_signature; }
         protected:
           signature_type m_signature;
        };

      template< typename return_name>
       class pure_class< return_name, void, void, void, void,void>
        : virtual public ::reflection::content::pure_class< return_name () >
        , virtual public ::reflection::property::function::pure_class<return_name,void,void,void,void,void>
        {
         public:
           typedef return_name    return_type;

           typedef ::reflection::content::pure_class< return_name () >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,void,void,void,void,void>   property_type;

           typedef std::array< ::reflection::type::string_type, 6 >   signature_type;

         public:
           pure_class()
            {
             m_signature[0] = typeid( return_name ).name();
             m_signature[1] = typeid(  void ).name();
             m_signature[2] = typeid(  void ).name();
             m_signature[3] = typeid(  void ).name();
             m_signature[4] = typeid(  void ).name();
             m_signature[5] = typeid(  void ).name();
            }

         public:
           using property_type::execute;

         public:
           signature_type const& signature()const{ return m_signature; }
         protected:
           signature_type m_signature;
        };


      }
    }
  }

#endif
