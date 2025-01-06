#pragma once
#include "raylib.h"
#include <string>

class SoundEffect {
private:
	Sound sound;
	bool loaded;

public:
	SoundEffect() { sound = { 0 }; }
	SoundEffect(std::string soundPath){
		sound = LoadSound(soundPath.c_str());
		loaded = true;
	}

	void play();
	void dispose();
};