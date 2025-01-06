#include "peargl.hpp"


void GameWindow::clear(){
	ClearBackground(background);
}

void GameWindow::start_frame(){
	// Make sure fps is up-to-date
	if (old_fps != fps){
		SetTargetFPS(fps);
		old_fps = fps;
	}

	BeginDrawing();
}

void GameWindow::start_camera_mode(){
	BeginMode2D(camera);
}

void GameWindow::end_camera_mode(){
	EndMode2D();
}

void GameWindow::end_frame(){
	EndDrawing();
}

void GameWindow::close(){
	CloseAudioDevice();
	CloseWindow();
}

bool GameWindow::window_open(){
	return !WindowShouldClose();
}