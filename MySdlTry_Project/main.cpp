#include "Game.h"

#include <iostream>

int main(int argc, char * argv[]) {
	
	Game *g = Game::Instance();
	g->Run();

	g->Release();
	g = NULL;

	system("pause");

	return 0;
}