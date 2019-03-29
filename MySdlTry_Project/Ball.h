#pragma once
#ifndef BALL_H
#define BALL_H

#include"Entity.h"
#include"Texture.h"
#include"Player.h"
#include<ctime>

class Ball : public Entity{
private:

	bool _leftStarts = true;
	bool _shoot = false;
	bool _shootMoment = false;

	unsigned int ticks = 0;

	float _vx, _vy;

	Texture *_tex;

public:

	Texture *GetTexture();

	void Update(Player *p1, Player *p2);
	void Render();

	void ProcessMovement(Player *p1, Player *p2);
	void Reset();

	void Shoot(bool x);
	bool Shoot();

	void RandVec();

	void ReverseVX();

	float VX();
	float VY();
public:

	Ball(float x, float y, std::string filename);
	Ball();
	~Ball();
};

#endif