#include "AssetManager.h"

AssetManager* AssetManager::_instance = NULL;

AssetManager* AssetManager::Instance() {

	if (_instance == NULL) _instance = new AssetManager();

	return _instance;
}

AssetManager::AssetManager(){

}


AssetManager::~AssetManager(){

	for (auto tex : _textures) {

		if(tex.second != NULL) SDL_DestroyTexture(tex.second);
	}
	_textures.clear();
}

void AssetManager::Release() {

	delete _instance;
	_instance = NULL;
}
SDL_Texture * AssetManager::GetTexture(std::string filename){

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	if (_textures[fullPath] == nullptr) {

		_textures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
	}

	return _textures[fullPath];
}