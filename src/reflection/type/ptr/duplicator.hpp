#ifndef Dh_DDMRM_memory_functor_duplicate_basic_HPP_
 #define Dh_DDMRM_memory_functor_duplicate_basic_HPP_


#ifndef TEMPLATE

 #ifdef __GNUC__
  #define   TEMPLATE template
 #else
  #define   TEMPLATE
 #endif

#endif

 namespace memory
  {
   namespace pointer
    {

     template
      <
        typename base_name
      >
     class duplicator
      {
       public:
         typedef base_name   base_type;

         typedef bool (*raw_type)( base_name **, base_name const * );

         duplicator():m_raw(NULL){ }

         template< typename derive_type, typename allocator_type >
          duplicator( derive_type , allocator_type )
           {
            this->template operator()<derive_type, allocator_type>(  );
           }

        ~duplicator(){ ; }

         template< typename derive_type, typename allocator_type >
          void operator()( void )const
           {
            m_raw = &GF_general< base_type, derive_type, allocator_type, bool >;
           }

         template< typename derive_type >
          bool operator()( base_type ** P_base, derive_type const* P_model )const
           {
            //std::cout << "duplicate::basic::operator()<"<<typeid( derive_type ).name() <<">" <<  std::endl;

            this->TEMPLATE operator()<derive_type, std::allocator< derive_type > >( );

            return Fvc_process( P_base, P_model );
           }


       public:
         bool operator() ( base_type **P_copy, base_type const* P_model )const
          {
           if( NULL != raw() )
            {
             return (*raw())( P_copy, P_model );
            }
           if( ( NULL == P_model ) && ( NULL != P_copy ) )
            {
             //! by definition: (ptr=NULL;) <=> ( delete ptr; )
             delete *P_copy;  //!< weak point;
             *P_copy = NULL;
             return bool( true );
            }

           //this->TEMPLATE operator()<base_type, std::allocator<base_type > >( ); zbog cisto virtuelnih klasa
           return bool( false );
          }

       public:
         raw_type const& raw( void )              const{ return m_raw; }
         bool     raw( raw_type const& P_raw )     { m_raw = P_raw; return bool( true ); }
       protected:
         raw_type     & F1_raw( void )                   { return m_raw; }
       private:
         mutable raw_type m_raw;

      };
    }
  }

#endif
