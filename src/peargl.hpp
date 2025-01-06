#pragma once
#include "raylib.h"
#include <map>
#include <iostream>

class GameWindow
{
private:
	int old_fps;

public:
	int width, height;
	std::string title;
	int fps;
	Color background;
	Camera2D camera;

	GameWindow(int width, int height, std::string title, int fps = 60):
		width(width), height(height), fps(fps), title(title), old_fps(fps){
		
		InitWindow(width, height, title.c_str());
		InitAudioDevice();
		SetTargetFPS(fps);
		camera = { 0 };
		camera.target = { 0, 0 };
		camera.rotation = 0;
		camera.zoom = 1.0f;
		camera.offset = { 0, 0 };
	}

	void clear();
	void start_frame();
	void start_camera_mode();
	void end_camera_mode();
	void end_frame();
	void close();
	bool window_open();
};






// Shapes




class RectangleShape {
private:
	void update_properties();
public:
	float x, y, width, height;
	Color color;
	bool visible;

	/// Must only be used by PearGL or when integrating RayLib.
	Rectangle rlib_rectangle;


	RectangleShape(float x, float y, float width, float height, Color color): x(x), y(y), width(width), height(height), color(color){
		rlib_rectangle = (Rectangle) { x, y, width, height };
	}

	void draw();
	float get_center_x();
	float get_center_y();
	bool is_colliding(RectangleShape with);
};







class TextureImage {
public:

	/// Must only be used by peargl or when integrating raylib
	Texture rlib_texture;

	/// Bounding rect
	RectangleShape rect;

	/// Color tint (white == no tint)
	Color tint;


	TextureImage(std::string imagePath, RectangleShape boundingRect, Color tint = WHITE): rect(boundingRect), tint(tint){
		rlib_texture = LoadTexture(imagePath.c_str());
	}

	TextureImage() : rect(0, 0, 0, 0, WHITE) { rlib_texture = { 0 }; }

	void draw();
	void dispose();
};




class TextureImageGroup {
private:
	std::map<std::string, TextureImage> textures;
	std::string current_texture;

public:
	/// Bounding rect for all textures
	RectangleShape rect;

	/**
	 * @brief Texture image group initializer
	 * @param rect The bounding rectangle for all the textures
	 * */
	TextureImageGroup(RectangleShape rect): rect(rect){}

	TextureImage* add_texture(std::string name, std::string imagePath, Color tint = WHITE);
	void remove_texture(std::string name);
	void set_current_texture(std::string name);
	void draw_current_texture();
	void dispose_all();
	
};





/* TEXT */

class Text {
public:
	std::string text;
	Color color;
	int size;
	float x, y;


	Text() : x(0), y(0), text(text), color(WHITE), size(0) {}
	Text(float x, float y, std::string text, Color color = BLACK, int size = 32) : x(x), y(y), text(text), color(color), size(size) {}


	void draw();
};