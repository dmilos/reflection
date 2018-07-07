#ifndef reflection_archive_schema_class
#define reflection_archive_schema_class
// ::reflection::archive::schema_class

namespace reflection
 {
  namespace  archive
   {

    template
     <
       typename key_name
      ,typename container_name
      ,typename find_name
      ,typename insert_name
      ,typename remove_name
     >
    class schema_class //!< kepp schema of class. No data. Only type/name i prototypes of functionss
     {
      public:
                 schema_class();
        virtual ~schema_class();

        // TODO find( )
        // TODO insert( )
        // TODO remove( )

     };

   }
 }

 #endif