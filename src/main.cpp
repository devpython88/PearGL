#include "PearGL"
#include "PearGL_Input"
#include "PearGL_Audio"

int main(){
	GameWindow window(800, 600, "Hello!");
	window.background = WHITE;

	RectangleShape rect(20, 40, 30, 30, RED);
	RectangleShape rect2(190, 230, 30, 30, BLUE);
	Text text(10, 20, "Hello!");
	SoundEffect sfx("./assets/expl.wav");
	
	while (window.window_open()){
		rect.x = Mouse::xPos() - rect.get_center_x();
		rect.y = Mouse::yPos() - rect.get_center_y();

		if (rect2.is_colliding(rect)) break;
		if (Mouse::pressed(Mouse::Button1)) sfx.play();
		
		window.start_frame();
		window.clear();
		rect.draw();
		rect2.draw();
		text.draw();
		window.end_frame();
	}

	sfx.dispose();
	window.close();
}