#ifndef reflection_define__begin
#define reflection_define__begin



#define reflection__CLASS_BEGIN_inherit( class_reflected, accesibility, class_original  )   \
  class class_reflected                                                                     \
   : accesibility class_original                                                            \
   , public ::reflection::content::class_class<class_original>                              \
   {                                                                                        \
    public:                                                                                 \
      typedef class_original original_type;                                                 \
                                                                                            \
      explicit class_reflected( original_type const& original )                             \
       :original_type(original){                                                            \
        this->init();                                                                       \
       }                                                                                    \
                                                                                            \
      class_reflected(  )                                                                   \
       {                                                                                    \
        this->init();                                                                       \
       }                                                                                    \
                                                                                            \
      explicit class_reflected( class_reflected const& other )                              \
       {                                                                                    \
        this->init();                                                                       \
       }                                                                                    \
                                                                                            \
   private:                                                                                 \
     void init()                                                                            \
      {

#define reflection__CLASS_BEGIN_member( class_reflected, accesibility, class_original  )   \
  class class_reflected                                                      \
   : public ::reflection::content::class_class<class_original>               \
   {                                                                         \
    public:                                                                  \
      typedef class_original original_type;                                  \
                                                                             \
      explicit class_reflected( original_type const& original )              \
       :m_original(original){                                                \
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
     original_type const& original()const                                    \
     {                                                                       \
      return m_original;                                                     \
     }                                                                       \
   protected:                                                                \
     original_type & original()                                              \
     {                                                                       \
      return m_original;                                                     \
     }                                                                       \
   accesibility:                                                             \
     original_type m_original;                                               \
   private:                                                                  \
     void init()                                                             \
      {


#define reflection__CLASS_BEGIN_view( class_reflected, accesibility, class_original, class_pointer    )   \
  class class_reflected                                                      \
   : public ::reflection::content::class_class<class_original>               \
   {                                                                         \
    public:                                                                  \
      typedef class_original original_type;                                  \
      typedef class_pointer  pointer_type;                                   \
                                                                             \
      explicit class_reflected( class_pointer const& pointer )               \
       :m_pointer(pointer){                                                  \
        this->init();                                                        \
       }                                                                     \
                                                                             \
      class_reflected()                                                      \
       :m_pointer(nullptr){                                                  \
        this->init();                                                        \
       }                                                                     \
                                                                             \
      explicit class_reflected( class_reflected const& other )               \
       :m_pointer(nullptr){                                                  \
        this->init();                                                        \
       }                                                                     \
   public:                                                                   \
     pointer_type const& pointer()const                                      \
      {                                                                      \
       return m_pointer;                                                     \
      }                                                                      \
     void pointer( pointer_type const& pointer_param )                       \
      {                                                                      \
       m_pointer = pointer_param;                                            \
       ::reflection::operation::reroute< pointer_type >( *this, this->pointer() );  \
      }                                                                      \
   protected:                                                                \
     pointer_type & pointer()                                                \
     {                                                                       \
      return m_pointer;                                                      \
     }                                                                       \
   accesibility:                                                             \
     pointer_type m_pointer;                                                 \
   private:                                                                  \
     void init()                                                             \
      {

#endif
