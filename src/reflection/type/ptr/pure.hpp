#ifndef memory_pointer_pure
#define memory_pointer_pure

 // memory::pointer::pure<N_class>

   namespace memory
    {
     namespace pointer
      {

       template
        <
          typename class_name
        >
        class pure
         {
          public:

           typedef class_name           class_type;
           typedef class_name*          raw_type;

         //typedef const class_type * const T_RawConst;

           typedef ::memory::pointer::pure<class_name> pure_type;

                     pure( void ){ ; }
           virtual  ~pure( void ){}

           virtual  class_type const* get( void )const=0;
           virtual  class_type      * get( void )=0;//{ return const_cast< pure_type const* >( this )-> get();  }

           virtual raw_type        release( void )=0; // I have NULL, you got original
           virtual void            destroy( void )=0; 
         //virtual raw_type        destroy( void )=0; //!< vraca NULL ako je unistenje uspelo;
           virtual void            reset( class_type *ptr_param = NULL )=0;
         //virtual raw_type        reset( class_type *ptr_param = NULL )=0; // obicno vraca ptr_param        

           pure_type& operator=( class_type * ptr_param ){ this->reset( ptr_param ); return *this; }
         //pure_type& operator=( pure_type const& P_original ) { reset( P_original.get() ); return *this }
           virtual class_type const& operator*()const { return *(this->get()); }
           virtual class_type      & operator*()      { return *(this->get()); }

           virtual class_type const*operator->()const{ return  this->get(); }
           virtual class_type      *operator->()     { return  this->get(); }

         };

      template<>
       class pure<void>
        {
         public:

           typedef void           class_type;
           typedef void*          raw_type;

           typedef pure<void> pure_type;

                   pure( void ){}
           virtual ~pure( void ){}

           virtual  void    const* get( void )const=0;
           virtual  void         * get( void )=0;//{ return const_cast< pure_type const* >( this )-> get();  }

           virtual raw_type        release( void )=0;
           virtual void         destroy( void )=0;
           virtual void         reset( class_type * ptr_param = NULL )=0;

         //virtual pure_type& operator=( pure_type const& P_original ) { reset( P_original.get() ); return *this }

           virtual class_type        operator*()const { return ; }
           virtual class_type        operator*()      { return ; }

           virtual class_type const*operator->()const{ return  this->get(); }
           virtual class_type      *operator->()     { return  this->get(); }

        };


       template< typename class_name > inline bool operator ==( ::memory::pointer::pure<class_name> const& left_param, ::memory::pointer::pure<class_name> const& right_param ){ return left_param.get() == right_param.get(); }
       template< typename class_name > inline bool operator !=( ::memory::pointer::pure<class_name> const& left_param, ::memory::pointer::pure<class_name> const& right_param ){ return left_param.get() != right_param.get(); }


       template< typename class_name >inline bool operator ==( void * left_param,  ::memory::pointer::pure<class_name> const& right_param ){ return left_param == right_param.get(); }
       template< typename class_name >inline bool operator !=( void * left_param,  ::memory::pointer::pure<class_name> const& right_param ){ return left_param != right_param.get(); }

       template< typename class_name >inline bool operator ==( ::memory::pointer::pure<class_name> const& left_param,  void * right_param ){ return left_param.get() == right_param; }
       template< typename class_name >inline bool operator !=( ::memory::pointer::pure<class_name> const& left_param,  void * right_param ){ return left_param.et() != right_param; }



    }
  }

#endif
