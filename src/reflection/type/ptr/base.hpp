#ifndef memory_pointer_base
#define memory_pointer_base

  // ::memory::pointer::base<class_name>

 #include "./pure.hpp"

   namespace memory
    {
     namespace pointer
      {

       template
        <
          typename class_name
       //,typename storage_name = class_name *
        >
        class base
         : public memory::pointer::pure<class_name>
         {
          public:

            typedef class_name   class_type;

            typedef class_name  *raw_type;
            typedef class_type  *carrier_type;

            typedef ::memory::pointer::pure<class_name>  pure_type;
            typedef ::memory::pointer::base<class_name>  base_type;

            explicit base( carrier_type const&  carrier_param = carrier_type( nullptr ) )
                     :m_carrier( carrier_param )
                     {
                     }

                    ~base()
                     {
                      this->F1_reset( nullptr ); 
                     }

            class_type const * get( void ) const
             {
              return  m_carrier;  //here goes something like convert<class_type>( m_carrier );
             }

            class_type       * get( void )
             {
              return  m_carrier;  //here goes something like convert<class_type>( m_carrier );
             }

            class_type* release( void )
             {
              class_type* I_tmp = this->get();
                                  this->F1_reset( nullptr );
              return I_tmp;
             }

            //using pure_type::operator=;
            base_type& operator=( base_type const& original_param )
             {
              this->F1_reset( original_param.get() );
              return *this;
             }

          protected:

            carrier_type& F1_reset( carrier_type const& carrier_param ) 
             {
              m_carrier = carrier_param; 
              return  m_carrier;      
             }
            carrier_type& F1_get()
             {
              return m_carrier; 
             }

          private:
            carrier_type m_carrier;
         };

       template< typename class_name > inline bool operator ==( ::memory::pointer::base<class_name> const& left_param, ::memory::pointer::base<class_name> const& right_param ){ return left_param.get() == right_param.get(); }
       template< typename class_name > inline bool operator !=( ::memory::pointer::base<class_name> const& left_param, ::memory::pointer::base<class_name> const& right_param ){ return left_param.get() != right_param.get(); }


       template< typename class_name >inline bool operator ==( void * left_param,  ::memory::pointer::base<class_name> const& right_param ){ return left_param == right_param.get(); }
       template< typename class_name >inline bool operator !=( void * left_param,  ::memory::pointer::base<class_name> const& right_param ){ return left_param != right_param.get(); }

       template< typename class_name >inline bool operator ==( ::memory::pointer::base<class_name> const& left_param,  void * right_param ){ return left_param.get() == right_param; }
       template< typename class_name >inline bool operator !=( ::memory::pointer::base<class_name> const& left_param,  void * right_param ){ return left_param.get() != right_param; }

    }
  }

 #endif

