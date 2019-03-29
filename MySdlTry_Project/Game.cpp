#include "Game.h"

Game *Game::_instance = NULL;



Game *Game::Instance()
{
	if (_instance == NULL)
		_instance = new Game();
	return _instance;
}


void Game::Release(){

	delete _instance;
	_instance = NULL;
}

Game::Game(){
	_running = false;
	_graphics = Graphics::Instance();

	_running = Graphics::Initialized();

	_timer = Timer::Instance();

	_handler = Handler::Instance(_graphics);

	_input = Input::Instance(_handler);
}


Game::~Game(){

	Graphics::Release();
	_graphics = NULL;

	Timer::Release();
	_timer = NULL;

	Handler::Release();
	_handler = NULL;

	Input::Release();
	_input = NULL;


}

void Game::Run() {
	static int ticks;


	while (_running) {
		_timer->Update();
		
		if (!_input->ProcessEvents()) {

			_running = false;
		}

		_handler->Update();

		if (_timer->DeltaTime() >= (1.0f / FRAME_RATE)) {	
			

		_handler->Render();

		_timer->Reset();

		printf("%d\n", ticks);
		ticks++;
		}
	}
}

void Game::UpdateKeyboard1(){

}

void Game::UpdateKeyboard2(){

}


