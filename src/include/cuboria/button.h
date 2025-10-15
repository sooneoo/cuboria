#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "object.h"


typedef struct Button {
    Object super;
    void (*click_callback)(struct Button*);
    void * param;
} Button;


#define BUTTON(T) ((Button*) (T)) 


static inline void button_click(Button * self) {
    self->click_callback(self);
}


#endif


