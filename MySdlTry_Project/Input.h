#pragma once
#ifndef INPUT_H
#define INPUT_H

#include"SDL.h"
#include"Handler.h"


class Input{
private:

	static Input *_instance;
		
	Handler *_handler;


	SDL_Event _event;

	const Uint8 *_keystate = SDL_GetKeyboardState(NULL);
public:

	static Input *Instance(Handler *_handler);
	static void Release();
	
	bool ProcessEvents();

public:
	Input(Handler *_handler);
	~Input();

};

#endif