#include "peargl.hpp"

void TextureImage::draw(){
	DrawTexture(rlib_texture, rect.x, rect.y, tint);
}

void TextureImage::dispose(){
	if (rlib_texture.id != 0) UnloadTexture(rlib_texture);
}



TextureImage* TextureImageGroup::add_texture(std::string name, std::string imagePath, Color tint){
	TextureImage texture(imagePath, rect, tint);
	textures[name] = texture;

	current_texture = name;

	return &textures[name];
}

void TextureImageGroup::remove_texture(std::string name){
	textures[name].dispose();
	textures.erase(name);
}

void TextureImageGroup::set_current_texture(std::string name){
	current_texture = name;
}

void TextureImageGroup::draw_current_texture(){
	textures[current_texture].draw();
}

void TextureImageGroup::dispose_all(){
	for (auto kvp : textures){
		kvp.second.dispose();
	}

	textures.clear();
}