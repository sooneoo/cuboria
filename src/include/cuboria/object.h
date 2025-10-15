#ifndef _OBJECT_H_
#define _OBJECT_H_


typedef struct Object {
    void (*draw)(struct Object *);
} Object;


#define OBJECT(T) ((Object*) (T))


static inline void object_draw(Object * self) {
    self->draw(self);
}


#endif


