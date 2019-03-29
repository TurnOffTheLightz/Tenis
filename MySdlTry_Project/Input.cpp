#include"Input.h"

Input *Input::_instance = NULL;

Input * Input::Instance(Handler *h)
{

	if (_instance == NULL) _instance = new Input(h);
	
	return _instance;
}

void Input::Release(){
	delete _instance;
	_instance = NULL;
}

bool Input::ProcessEvents(){
	if (SDL_PollEvent(&_event) != 0) {

		if (_event.type == SDL_QUIT || _event.key.keysym.sym == SDLK_ESCAPE) {

			return false;
		}
		if (_event.type == SDL_KEYDOWN) {

			if (_keystate[SDL_SCANCODE_W]) {

				_handler->PlayerLeft()->MoveUp();
			}
			if (_keystate[SDL_SCANCODE_S]) {

				_handler->PlayerLeft()->MoveDown();
			}
			if (_keystate[SDL_SCANCODE_UP]) {

				_handler->PlayerRight()->MoveUp();
			}
			if (_keystate[SDL_SCANCODE_DOWN]) {

				_handler->PlayerRight()->MoveDown();
			}
			if (_keystate[SDL_SCANCODE_SPACE]) {

				_handler->Space(true);
			}
		}
	}

	return true;
}

Input::Input(Handler *h){

	_handler = h;
}
Input::~Input(){

	_handler = NULL;
}
