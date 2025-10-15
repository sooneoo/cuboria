#include "cuboria/game_state_game_control.h"


static GameState * game_state_game_control_callback(
        GameState * self, GameManager_Context * context) {
    DrawText("Game Control", 400, 300, 40, BLACK);

    UpdateCamera(&context->camera, CAMERA_FREE); 
    BeginMode3D(context->camera);
    DrawModel(context->cube, (Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, WHITE);

    DrawGrid(10, 1.0f);
    EndMode3D();

    if(IsKeyPressed(KEY_SPACE) == true) {
        return context->state_stack[GameState_ID_Pause];
    } else {
        return context->state_stack[GameState_ID_GameControl];
    }
}


GameState_GameControl game_state_game_control(void) {
    return (GameState_GameControl) {
        .super = {
            .callback = game_state_game_control_callback
        }
    };
}


