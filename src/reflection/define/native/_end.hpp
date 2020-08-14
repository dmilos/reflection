#ifndef reflection_define__end
#define reflection_define__end



#define reflection__CLASS_END_member(class_member_reflected,class_original) \
        ::reflection::operation::reroute< class_original* >( *this, &this->original() ); \
        return;            \
       } \
    }

#define reflection__CLASS_END_inherit(class_inherit_reflected,class_original) \
        ::reflection::operation::reroute< class_original* >( *this, this ); \
        return;            \
       } \
    }

#define reflection__CLASS_END_view(class_view,class_original) \
        if( nullptr != this->pointer() ) \
         {\
          ::reflection::operation::reroute< class_view::pointer_type >( *this, this->pointer() );\
         } \
        return;            \
       } \
    }

#endif
