#ifndef _GAME_CONTEXT_H_
#define _GAME_CONTEXT_H_ 

#include <raylib.h>


typedef enum {
    GameState_ID_Menu
    , GameState_ID_Options
    , GameState_ID_Pause
    , GameState_ID_GameControl
    , GameState_ID_GameOver
    , GameState_ID_N
} GameState_ID ;


typedef struct GameState GameState;


typedef struct {
	GameState ** state_stack;
    float frame_time;

    Camera3D camera;
} GameManager_Context;


struct GameState {
	struct GameState * (*callback)(struct GameState *, GameManager_Context *);
};


#endif


