#include"Timer.h"

Timer *Timer::_instance = NULL;

Timer::Timer() {

	Reset();
}

Timer::~Timer() {
	
}

Timer *Timer::Instance(){

	if (_instance == NULL)
		_instance = new Timer();
	return _instance;
}

void Timer::Release(){

	delete _instance;
	_instance = NULL;
}

void Timer::Reset() {

	_startTicks = SDL_GetTicks();
	_ticksTotal = 0;
	_deltaTime = 0;
}

float Timer::DeltaTime(){

	return _deltaTime;
}

void Timer::Update()
{

	_ticksTotal = SDL_GetTicks() - _startTicks;
	_deltaTime = _ticksTotal * 0.001f;
}
