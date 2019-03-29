#include"Texture.h"



void Texture::Render() {

	_graphics->DrawTexture(_tex,  NULL, &_renderRect);
}

SDL_Rect *Texture::GetTextureRect(){

	return &_renderRect;
}

void Texture::UpdateRectXY(float y){

	_renderRect.y = (int)y;
}

void Texture::UpdateRectXY(float x, float y){

	_renderRect.x = (int)x;
	_renderRect.y = (int)y;
}

Texture::Texture(std::string filename, float x, float y, int w, int h){

	_graphics = Graphics::Instance();

	_tex = AssetManager::Instance()->GetTexture(filename);

	_width = w;
	_height = h;
	X(x);
	Y(y);

	_renderRect.x = (int)X();
	_renderRect.y = (int)Y();
	_renderRect.w = _width;
	_renderRect.h = _height;
}

Texture::~Texture(){

	_graphics = NULL;
	_tex = NULL;
}
