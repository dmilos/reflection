#ifndef reflection_define__begin
#define reflection_define__begin



#define reflection__CLASS_BEGIN_inherit( class_reflected, accesibility, class_original  )  \
  class class_reflected                                                      \
   : accesibility class_original                                             \
   , public ::reflection::content::class_class<class_original>               \
   {                                                                         \
    public:                                                                  \
      typedef class_original original_type;                                  \
                                                                             \
      explicit class_reflected( original_type const& original )              \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
                                                                             \
      class_reflected(  )                                                    \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
                                                                             \
      explicit class_reflected( class_reflected const& other )               \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
                                                                             \
   private:                                                                  \
     void init()                                                             \
      {

#define reflection__CLASS_BEGIN_member( class_reflected, accesibility, class_original  )   \
  class class_reflected                                                      \
   : public ::reflection::content::class_class<class_original>               \
   {                                                                         \
    public:                                                                  \
      typedef class_original original_type;                                  \
                                                                             \
      explicit class_reflected( original_type const& original )              \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
                                                                             \
      class_reflected()                                                      \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
                                                                             \
      explicit class_reflected( class_reflected const& other )               \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
   public:                                                                   \
     original_type const& original()                                         \
     {                                                                       \
      return m_original;                                                     \
     }                                                                       \
   accesibility:                                                             \
     original_type m_original;                                               \
   private:                                                                  \
     void init()                                                             \
      {

#endif
