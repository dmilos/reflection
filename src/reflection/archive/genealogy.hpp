#ifndef reflection_archive_genealogy_class
#define reflection_archive_genealogy_class

// ::reflection::archive::genealogy_class

namespace reflection
 {
  namespace  archive
   {

     template
      <
        typename identifier_name
       ,typename relation_name
       ,typename report_name
      >
      class genealogy_class
       {
        public:
          typedef identifier_name     identifier_type;
          typedef relation_name         relation_type;
          typedef report_name             report_type;

          typedef identifier_type leftName_type, rightName_type;

          typedef std::map<rightName_type,relation_type>      rightTable_type;
          typedef std::map<leftName_type,relation_type>        leftTable_type;
          typedef std::set<identifier_type>                          all_type;
          typedef std::map<rightName_type,leftTable_type>             up_type;
          typedef std::map<leftName_type,rightTable_type >          down_type;

        public:
          genealogy_class(){}
         ~genealogy_class(){}

         leftTable_type const& left( rightName_type const& identifier_param )const
           {
            static const leftTable_type Irc_empty;
            auto iterator = M2_up.find( identifier_param );
            if( iterator == M2_up.end() )return Irc_empty;
            return iterator->second;
           }

          rightTable_type  const& right( leftName_type const& identifier_param )const
           {
            static const rightTable_type Irc_empty;
            auto itrator = M2_down.find( identifier_param );
            if( itrator == M2_down.end() )return Irc_empty;
            return itrator->second;
           }

          report_type        relate( leftName_type const& left_param, rightName_type const& right_param, relation_type const& relation_param )
           { // left _relation_ right.  Derived _derived_ Base. Base _base_ Derived
            auto I_right = M2_down.find( left_param );
            if( I_right == M2_down.end() )
             {
              I_right = M2_down.emplace( left_param, rightTable_type{} ).first;
             }
            I_right->second.emplace( right_param, relation_param );

            auto I_left = M2_up.find( right_param );
            if( I_left == M2_up.end() )
             {
              I_left = M2_up.emplace( right_param, leftTable_type{} ).first;
             }
            I_left->second.emplace( left_param, relation_param );

            M2_all.emplace( left_param );
            M2_all.emplace( right_param );

            return report_type( true );
           }

        //report_type        separate( leftName_type const& left_param, rightName_type const& right_param );

          void     clear()
           {
            M2_all.clear();
            M2_up.clear();
            M2_down.clear();
           }

          report_type insert( identifier_type const& identifier_param )
           {
            M2_all.emplace( identifier_param );

            if( M2_up.end() == M2_up.find( identifier_param ) )
             {
              M2_up.emplace( identifier_param, leftTable_type{} );
             }

            if( M2_down.end() == M2_down.end() )
             {
              M2_down.emplace( identifier_param, rightTable_type{} );
             }

            return report_type( true );
           }

          report_type erase(  identifier_type const& identifier_param )
           {
            M2_all.erase( identifier_param );

            auto I_up = M2_up.find( identifier_param );
            if( I_up != M2_up.end()  )
             {
              leftTable_type &I_left = I_up->second;

              for( auto I_left_iter  = I_left.begin();
                                                 I_left_iter != I_left.end();
                                               ++I_left_iter
                 )
               {
                auto I_down = M2_down.find( I_left_iter->first );
                if( I_down != M2_down.end() )
                 {
                  I_down ->second.erase( identifier_param );
                  if( 0 == I_down->second.size() )
                   {
                    M2_down.erase( I_down );
                   }
                 }
               }
              M2_up.erase( I_up );
             }

            auto I_down = M2_down.find( identifier_param );
            if( I_down != M2_down.end() )
             {
              T_right &I_right = I_down->secnd;
           
              for( auto I_right_iter  = I_right.begin();
                                                 I_right_iter != I_right.end();
                                               ++I_right_iter
                 )
               {
                auto I_up = M2_up.find( I_right_iter->first );
                if( I_up != M2_up.end() )
                 {
                  I_up->second.erase( identifier_param );
                  if( 0 == I_up->second.size() )
                   {
                    M2_up.erase( I_up );
                   }
                 }
               }
              M2_down.erase( I_down );
             }

            return report_type( true );
           }

        protected:
          report_type relation( relation_type & relation_param,  leftName_type const& left_param, rightName_type  const& right_param )
           {  
            auto I_down = M2_down.find( identifier_param );
            if( I_down == M2_down.end() )
              {
               return  report_type( false );
              }
            auto I_down->second.find( right_param )

            return T_report(true);
           }

        public:
          all_type    const& all( void )const{ return M2_all; }
        private:
          all_type    M2_all;

        public:
          up_type     const& up( void )const{ return M2_up; }
        private:
          up_type     M2_up;

        public:
          down_type   const& down( void )const{ return M2_down; }
        private:
          down_type   M2_down;
       };


   }
 }

 #endif