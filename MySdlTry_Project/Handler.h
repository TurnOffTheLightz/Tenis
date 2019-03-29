#pragma once
#ifndef HANDLER_H
#define HANDLER_H
#include"Player.h"
#include"Texture.h"
#include"Ball.h"

#include<vector>

class Handler {
private:

	static Handler*_instance;

	Graphics* _graphics;

	std::vector<Player> _players;

	Texture *_backgroundImg;

	Ball *_ball;

	bool _space = false;
public:

	static Handler* Instance(Graphics *g);
	static void Release();

	void Render();
	void Update();

	void Space(bool x);
	bool Space();

	Player *PlayerLeft();
	Player *PlayerRight();

private:

	void CreatePlayers();
	void AddPlayer(Player &p);
public:

	Handler(Graphics *g);
	~Handler();
	
};

#endif