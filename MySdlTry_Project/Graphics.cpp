#include "Graphics.h"

#include"SDL_image.h"
#include"SDL_ttf.h"


Graphics *Graphics::_instance = NULL;

bool Graphics::_initialized = false;

Graphics::Graphics()
{
	_initialized = Init();
}


Graphics::~Graphics()
{

	SDL_DestroyWindow(_window);
	_window = NULL;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
Graphics *Graphics::Instance()
{

	if (_instance == NULL)
		_instance = new Graphics();

	return _instance;
}
void Graphics::Release()
{

	delete _instance;
	_instance = NULL;
}
bool Graphics::Initialized()
{

	return _initialized;
}
bool Graphics::Init()
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;

	if (TTF_Init() == -1) return false;

	_window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, NULL);

	if (_window == NULL) return false;

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == NULL) return false;

	SDL_SetRenderDrawColor(_renderer, 0xff, 0xff, 0xff, 0xff);

	int flags = IMG_INIT_PNG;

	if (!(IMG_Init(flags) & flags)) return false;

	return true;
}

void Graphics::ClearBackBuffer(){

	SDL_RenderClear(_renderer);
}

void Graphics::DrawTexture(SDL_Texture *tex, SDL_Rect * r1, SDL_Rect * r2){
	
	SDL_RenderCopy(_renderer, tex, r1, r2);
}

void Graphics::Render() {
	//show final render result
	SDL_RenderPresent(_renderer);
}

void Graphics::PrintScore(std::string s1, std::string s2){

	std::string output;
	output.append(s1);
	output.append(" : ");
	output.append(s2);

	TTF_Font *Sans = TTF_OpenFont("../Debug/arial.ttf", 25);
	SDL_Color White = { 0, 0, 0 };  

	if (Sans == NULL) printf("EROR\n\n\n\n");

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, output.c_str(), White);
		
	SDL_Texture* Message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);

	SDL_Rect Message_rect = {350,50,100,100};

	SDL_RenderCopy(_renderer, Message, NULL, &Message_rect); 

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(Sans);
}

SDL_Texture* Graphics::LoadTexture(std::string filename) {

	SDL_Texture *newTexture = NULL;

	SDL_Surface* surf = IMG_Load(filename.c_str());

	if (surf == NULL) {	printf("Error loading path: %s\n", filename.c_str());

		SDL_FreeSurface(surf);
		return newTexture;
	}
	else {

		newTexture = SDL_CreateTextureFromSurface(_renderer, surf);

		SDL_FreeSurface(surf);
	}
	return newTexture;
}