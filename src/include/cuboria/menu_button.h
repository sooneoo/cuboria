#ifndef _MENU_BUTTON_H_
#define _MENU_BUTTON_H_ 

#include "button.h"


typedef struct {
    Button super;
} Menu_Button;


Menu_Button menu_button(void (*click_callback) (Button*), void * param);


#endif


