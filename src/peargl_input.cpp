#include "peargl_input.hpp"


bool Keyboard::pressed(int key){
	return IsKeyPressed(key);
}

bool Keyboard::held(int key){
	return IsKeyDown(key);
}

bool Keyboard::released(int key){
	return IsKeyReleased(key);
}




bool Mouse::pressed(int button){
	return IsMouseButtonPressed(button);
}

bool Mouse::held(int button){
	return IsMouseButtonDown(button);
}

bool Mouse::released(int button){
	return IsMouseButtonReleased(button);
}

	



int Mouse::xPos(){
	return GetMouseX();
}

int Mouse::yPos(){
	return GetMouseY();
}

	