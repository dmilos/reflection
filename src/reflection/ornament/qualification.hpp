#ifndef reflection_ornament_qualification
#define reflection_ornament_qualification

// ::reflection::ornament::qualification_class

#include "../property/_pure.hpp"

namespace reflection
 {
  namespace ornament
   {
   
   namespace _internal
    {   //       https://stackoverflow.com/questions/30407754/how-to-test-if-a-method-is-const
     template<class T> 
     struct is_pointer_to_const_member_function : std::false_type {};

     template<class R, class T, class... Args> 
     struct is_pointer_to_const_member_function<R (T::*)(Args...) const> : std::true_type {};

     template<class R, class T, class... Args> 
     struct is_pointer_to_const_member_function<R (T::*)(Args..., ...) const> : std::true_type {};

     template<class T> 
     struct is_pointer_to_volatile_member_function : std::false_type {};

     template<class R, class T, class... Args> 
     struct is_pointer_to_volatile_member_function<R (T::*)(Args...) volatile> : std::true_type {};

     template<class R, class T, class... Args> 
     struct is_pointer_to_volatile_member_function<R (T::*)(Args..., ...) volatile> : std::true_type {};
    }


    class qualification_class
     : virtual public ::reflection::property::pure_class
     {
      public:
        typedef enum qualification_enum
          {
                default_index = 0
              ,  friend_index = 1
              ,   const_index = 2
              , mutable_index = 4
              ,volatile_index = 8
              ,      cv_index = const_index + volatile_index
          } qualification_type;

      public:
         qualification_class( )
          :m_qualification(default_index)
          {
          }
         explicit qualification_class( qualification_enum const& r )
          :m_qualification(r) 
          {
          }
        virtual ~qualification_class(){}

       template< typename type_name>
        static qualification_enum get()
         {
          unsigned result =  default_index;

          if( std::is_const< type_name >   () ) result |=  const_index;
          if( std::is_volatile< type_name >() ) result |=  volatile_index;

          {
           typedef typename std::remove_reference<type_name>::type no_ref_type;
           if( ::reflection::ornament::_internal::is_pointer_to_const_member_function< no_ref_type >() ) result |=  const_index;
          }

          {
           typedef typename std::remove_reference<type_name>::type no_ref_type;
           if( ::reflection::ornament::_internal::is_pointer_to_volatile_member_function< no_ref_type >() ) result |=  volatile_index;
          }

          //if( _internal::is_pointer_to_volatile_member_function< type_name >() ) result |=  volatile_index;

        //if( std::is_mutable< type_name >()  ) result |=  mutable_index;

          return (qualification_enum)result;
         }

      public:
        qualification_type const& qualification()const
         {
          return m_qualification; 
         }
        void                      qualification( qualification_enum const& qualification_param )
         {
          m_qualification = qualification_param; 
         }
      protected:
        qualification_type      & qualification()     
         {
          return m_qualification; 
         }

      private:
        qualification_type m_qualification;
     };

   }
 }

#endif
