#pragma once

#ifndef _GRAPHICS_H
#define _GRAPHICS_H
#include"SDL.h"
#include <string>

class Graphics
{
public:
	const int SCREEN_W = 800;
	const int SCREEN_H = 600;
	const char* TITLE = "MY SDL TRY";
private:
	static bool _initialized;

	static Graphics*_instance;

	SDL_Window *_window;
	SDL_Renderer *_renderer;
public:

	static Graphics*Instance();

	static void Release();

	static bool Initialized();

	bool Init();

	void ClearBackBuffer();
	void DrawTexture(SDL_Texture*tex, SDL_Rect*r1 = NULL, SDL_Rect*r2 = NULL);
	void Render();
	void PrintScore(std::string s1, std::string s2);

	SDL_Texture *LoadTexture(std::string filename);
public:
	Graphics();
	~Graphics();
};

#endif
