#include "peargl.hpp"





void RectangleShape::draw(){
	update_properties(); // everything uptodate
	DrawRectangleRec(rlib_rectangle, color);
}

float RectangleShape::get_center_x(){
	return width / 2;
}

float RectangleShape::get_center_y(){
	return height / 2;
}

bool RectangleShape::is_colliding(RectangleShape with){
	update_properties();
	return CheckCollisionRecs(rlib_rectangle, with.rlib_rectangle);
}

void RectangleShape::update_properties(){
	rlib_rectangle.x = x;
	rlib_rectangle.y = y;
	rlib_rectangle.width = width;
	rlib_rectangle.height = height;
}