#pragma once
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <map>
#include "Graphics.h"

class AssetManager
{
private:

	static AssetManager* _instance;
	std::map<std::string, SDL_Texture*> _textures;
public:

	static AssetManager* Instance();
	static void Release();

	SDL_Texture* GetTexture(std::string filename);
public:
	AssetManager();
	~AssetManager();
};

#endif

