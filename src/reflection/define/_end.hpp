#ifndef reflection_define__end
#define reflection_define__end



#define reflection__CLASS_END_member(class_reflected,class_original) \
        ::reflection::operation::reroute< class_original* >( *this, &this->original() ); \
        return;            \
       } \
    }


#define reflection__CLASS_END_inherit(class_reflected,class_original) \
        ::reflection::operation::reroute< class_original* >( *this, this ); \
        return;            \
       } \
    }


#define reflection__CLASS_END_view(class_reflected,class_original) \
        if( nullptr != this->pointer() ) \
         {\
          ::reflection::operation::reroute< class_reflected::pointer_type >( *this, this->pointer() );\
         } \
        return;            \
       } \
    }


#endif
