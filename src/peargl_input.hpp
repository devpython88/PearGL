#pragma once
#include <iostream>
#include "raylib.h"



class Keyboard {
public:
	static bool pressed(int key);
	static bool held(int key);
	static bool released(int key);
};

class Mouse {
public:
	static const int Button1 = MOUSE_BUTTON_LEFT;
	static const int Button2 = MOUSE_BUTTON_RIGHT;
	static const int Button3 = MOUSE_BUTTON_MIDDLE;
	

	static bool pressed(int button);
	static bool held(int button);
	static bool released(int button);
	
	static int xPos();
	static int yPos();
	
};