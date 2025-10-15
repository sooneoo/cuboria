#include "cuboria/menu_button.h"


static void menu_button_draw(Object * self) {
    
}


Menu_Button menu_button(void (*click_callback) (Button*), void * param) {
    return (Menu_Button) {
        .super = {
            .super = {
                .draw = menu_button_draw
            }
            , .click_callback = click_callback
            , .param = param
        }  
    };
}



