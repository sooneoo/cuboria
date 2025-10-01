#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

#define WINDOW_TITLE "Cuboria"



int main(void) {
	InitWindow(800, 600, WINDOW_TITLE);
	SetConfigFlags(FLAG_VSYNC_HINT);
	SetTargetFPS(144);

	while(WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(WHITE);
		EndDrawing();
	}

	CloseWindow();

	return EXIT_SUCCESS;
}

