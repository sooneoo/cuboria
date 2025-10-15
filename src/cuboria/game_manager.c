#include "cuboria/game_manager.h"
#include <raylib.h>


GameManager game_manager(GameState * init_state, GameState ** state_stack) {
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; 

	return (GameManager) {
		.context = {
			.state_stack = state_stack
            , .camera = camera
		}
		, .state = init_state
	};
}


void game_manager_execute(GameManager * self) {
	self->context.frame_time = GetFrameTime();
	self->state = self->state->callback(self->state, &self->context);
}



