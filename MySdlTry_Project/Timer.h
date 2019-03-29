#pragma once
#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"

class Timer {

private:

	static Timer *_instance;

	unsigned int _startTicks;
	unsigned int _ticksTotal;
	float _deltaTime;

public:

	static Timer *Instance();
	static void Release();

	void Reset();
	float DeltaTime();

	void Update();
private:

	Timer();
	~Timer();
};

#endif