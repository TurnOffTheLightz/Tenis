#pragma once
#ifndef _GAME_H
#define _GAME_H
#include"Graphics.h"
#include"Timer.h"
#include"Input.h"

#include<iostream>


class Game
{
private:

	static Game *_instance;
	const int FRAME_RATE = 60;
	bool _running;

	Graphics *_graphics;

	Timer *_timer;

	Handler *_handler;

	Input *_input;
public:

	 static Game* Instance();

	 static void Release();

	 void Run();

	 void UpdateKeyboard1();
	 void UpdateKeyboard2();

public:
	Game();
	~Game();
};

#endif