#include "peargl_audio.hpp"


void SoundEffect::play(){
	PlaySound(sound);
}

void SoundEffect::dispose(){
	if (loaded){
		UnloadSound(sound);
		loaded = false;
	}
}
