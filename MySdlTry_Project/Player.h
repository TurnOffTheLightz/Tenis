#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include"Entity.h"
#include"Texture.h"

class Player : public Entity{
public:

	enum PLAYER { left = 1, right = 2 };
private:

	const float VEL = 15.0f;

	int score = 0;

	PLAYER _side; 

	Texture *_tex;

public:

	Texture *GetTexture();

	void Update();
	void Render();

	void MoveUp();
	void MoveDown();

	void AddScore();

	std::string Score();

	Player(float x, float y, std::string filename, PLAYER s);
	~Player();
};

#endif