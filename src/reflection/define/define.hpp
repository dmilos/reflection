#define reflection__CLASS_BEGIN_inherit( class_original, class_reflected, class_model )
  class class_reflected : class_original
   {
    public:
      typedef original_original;
      class_reflected(){}
      explicit class_reflected( class_reflected const& other )
       {
        this->init();
        assign
       }

      explicit class_reflected( class_original const& original )
       {
        this->init();
       }

   private:
     void init()
      {

#define reflection__CLASS_BEGIN_member(  class_original, class_reflected, class_model )
  class class_reflected
   {
    public:
      typedef class_original original_type;
      class_reflected(){}
      explicit class_reflected( class_original const& riginal )
       {

#define reflection__CLASS_MEMBER_function(    member_name,     class_original::asdas   )

#define reflection__CLASS_FUNCTION_free(      function_name,   class_original::asdas   )

#define reflection__CLASS_FUNCTION_member(    function_name,   inspector   )
  insert(  "m2",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, inspector ) ) ) );

#define reflection__CLASS_MEMBER_big(         member_name,     class_original::asdas   )

#define reflection__CLASS_MEMBER_direct(      member_name,     class_original::asdas   )
       insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<int>( 10 ) ) ) );

#define reflection__CLASS_MEMBER_guarded(     member_name,     mutator, inspector   )
  insert(  member_name, item_type( ::memory::pointer::make( ::reflection::content::guarded::member( this, mutator, inspector ) ) ) );


#define reflection__CLASS_MEMBER_inspect(     member_name,     class_original::asdas   )
#define reflection__CLASS_MEMBER_mutate(      member_name,     class_original::asdas   )

#define reflection__CLASS_MEMBER_reset(       member_name,     class_original::asdas   )
#define reflection__CLASS_MEMBER_variable(    member_name, inspector, traitor   )
  insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::variable::member(  this, &MyClass::inspector, &MyClass::traitor   ) ) ) );

#define reflection__CLASS_END() \
        return;
       } \
    };