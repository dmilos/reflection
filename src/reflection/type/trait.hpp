#ifndef reflection_type_add_lconst_value_reference
#define reflection_type_add_lconst_value_reference

// ::reflection::type::add_lconst_value_reference

namespace reflection
 {
  namespace type
   {

    template < typename type_name >
     struct trait
      {
       public:
         typedef  type_name               instance_type;     //!< Something that must instacible

         typedef  type_name      const    const_type, instance_const_type; //!< constant instance

         typedef  instance_type       &   original_type;  //!< Original object.

         typedef  instance_type       *   pointer_type;
         typedef  instance_type  const*   pointer_const_type;

         typedef  instance_type  const&       image_type;  //!< Return type that can not be changed. Might or might not be reference
         typedef  instance_type           pretender_type;  //!< Return type that can be changed, but without effect.

         typedef  instance_type  const&      model_type;  //!< Input type that can NOT be changed
         typedef  instance_type              input_type;  //!< Input type that can be change. Effect might or might be visible to outside. Prefer NOT.
         typedef  instance_type       &     output_type;  //!< Output type that can be changed. Must have outside effect.
         typedef  instance_type       &   transmit_type;  //!< Input and output at the same time.
      };

    template < typename type_name >
     struct trait< type_name & > : public ::reflection::type::trait< type_name >
      {
      };

    template < typename type_name >
     struct trait< type_name const> : public ::reflection::type::trait< type_name >
      {
      };

    template < typename type_name >
     struct trait< type_name const& > : public ::reflection::type::trait< type_name >
      {
      };

    template < >
     struct trait<void>
      {
       public:
         typedef  void               instance_type;     //!< Something that must instacible

         typedef  void   const_type, instance_const_type; //!< constant instance

         typedef  void  original_type;  //!< Original object.

         typedef  void  pointer_type;
         typedef  void  pointer_const_type;

         typedef  void   image_type;      //!< Return type that can not be changed. Might or might not be reference
         typedef  void   pretender_type;  //!< Return type that can be changed, but without effect.

         typedef  void      input_type;  //!< Input type that can be change. Effect might or might be visible to outside. Prefer NOT.
         typedef  void     output_type;  //!< Output type that can be changed. Must have outside effect.
         typedef  void   transmit_type;  //!< Input and output at the same time.
      };

   }
 }

#endif