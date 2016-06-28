#ifndef mamoery_pointer_make
 #define mamoery_pointer_make

 namespace memory
  {
   namespace pointer
    {

     template
      <
        typename class_name
      >
      inline
      class_name *
      make( class_name const& class_param )
       {
        return new class_name{ class_param };
       }

    }
  }

#endif
