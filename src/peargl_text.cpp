#include "peargl.hpp"


void Text::draw(){
	DrawText(text.c_str(), x, y, size, color);
}
