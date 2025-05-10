#ifndef reflection_define__begin
#define reflection_define__begin

// reflection__CLASS_BEGIN_inherit( reflection, public/protected/private, original )
// reflection__CLASS_BEGIN_member( reflection, public/protected/private, original )
// // obsolete reflection__CLASS_BEGIN_view(  reflection,  public/protected/private, original, pointer )
// reflection__CLASS_BEGIN_pointer(  reflection,  public/protected/private, original, pointer )
// reflection__CLASS_BEGIN_reference(  reflection,  public/protected/private, original, pointer )


#define reflection__CLASS_BEGIN_inherit( class_reflected, accessibility_name, class_original )   \
  class class_reflected                                                                          \
   : accessibility_name class_original                                                           \
   , public ::reflection::content::class_class<class_original>                                   \
   {                                                                                             \
    private:                                                                                     \
      typedef ::reflection::content::class_class<class_original> private_base_type;              \
    public:                                                                                      \
      typedef class_original original_type;                                                      \
      typedef class_original* pointer_type;                                                      \
                                                                                                 \
    public:                                                                                      \
                                                                                                 \
      class_reflected()                                                                          \
       {                                                                                         \
        this->init();                                                                            \
       }                                                                                         \
      explicit class_reflected( original_type const& original )                                  \
       :original_type(original)                                                                  \
       {                                                                                         \
        this->init();                                                                            \
       }                                                                                         \
                                                                                                 \
   private:                                                                                      \
     void init()                                                                                 \
      {

#define reflection__CLASS_BEGIN_member( class_reflected, accessibility_name, class_original )   \
  class class_reflected                                                      \
   : public ::reflection::content::class_class<class_original>               \
   {                                                                         \
    public:                                                                  \
      typedef class_original original_type;                                  \
      typedef class_original* pointer_type;                                  \
                                                                             \
      class_reflected()                                                      \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
                                                                             \
      explicit class_reflected( original_type const& original )              \
       :m_original(original){                                                \
        this->init();                                                        \
       }                                                                     \
                                                                             \
    public:                                                                  \
      original_type const& original()const                                   \
       {                                                                     \
        return m_original;                                                   \
       }                                                                     \
    protected:                                                               \
      original_type & original()                                             \
       {                                                                     \
        return m_original;                                                   \
       }                                                                     \
    accessibility_name:                                                      \
      original_type m_original;                                              \
    private:                                                                 \
      void init()                                                            \
       {

#define reflection__CLASS_BEGIN_reference( class_reflected, accessibility_name, class_original, class_reference )   \
  class class_reflected                                                      \
   : public ::reflection::content::class_class<class_original>               \
   {                                                                         \
    public:                                                                  \
      typedef class_original original_type;                                  \
      typedef class_reference  reference_type;                               \
      /*typedef class_original *pointer_type;   */                           \
      typedef typename std::remove_reference<class_reference>::type *pointer_type;  \
                                                                             \
      class_reflected( reference_type  reference )                           \
       :m_reference(reference){                                              \
        this->init();                                                        \
       }                                                                     \
                                                                             \
    public:                                                                  \
      reference_type & reference()                                           \
       {                                                                     \
        return m_reference;                                                  \
       }                                                                     \
    accessibility_name:                                                      \
      reference_type m_reference;                                            \
    private:                                                                 \
      void init()                                                            \
       {

#define reflection__CLASS_BEGIN_pointer( class_reflected, accessibility_name, class_original, pointer_class )   \
  class class_reflected                                                      \
   : public ::reflection::content::class_class<class_original>               \
   {                                                                         \
    public:                                                                  \
      typedef class_original original_type;                                  \
      typedef pointer_class   pointer_type;                                  \
      typedef const pointer_type  pointer_const_type;                        \
                                                                             \
      class_reflected()                                                      \
       :m_pointer(nullptr)                                                   \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
                                                                             \
      explicit class_reflected( pointer_const_type const&  pointer )         \
       :m_pointer(pointer)                                                   \
       {                                                                     \
        this->init();                                                        \
       }                                                                     \
                                                                             \
   public:                                                                   \
     pointer_type const& pointer()const                                      \
      {                                                                      \
       return m_pointer;                                                     \
      }                                                                      \
     void pointer( pointer_type const& pointer_param )                       \
      {                                                                      \
       m_pointer = pointer_param;                                            \
       ::reflection::operation::reroute::set( *this, this->pointer() );      \
      }                                                                      \
   protected:                                                                \
     pointer_const_type & pointer()                                          \
      {                                                                      \
       return m_pointer;                                                     \
      }                                                                      \
   accessibility_name:                                                       \
     pointer_type m_pointer;                                                 \
   private:                                                                  \
     void init()                                                             \
      {

#endif
