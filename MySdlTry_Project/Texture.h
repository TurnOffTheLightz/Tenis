#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H
#include"Entity.h"
#include"AssetManager.h"

class Texture : public Entity{
private:

	SDL_Texture *_tex;

	Graphics *_graphics;
	
	int _width;
	int _height;

	SDL_Rect _renderRect;

public:
	virtual void Render();

	SDL_Rect *GetTextureRect();

	void UpdateRectXY(float y);
	void UpdateRectXY(float x, float y);
	Texture(std::string filename, float x, float y,int w,int h);
	~Texture();

};

#endif