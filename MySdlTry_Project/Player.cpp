#include "Player.h"

Player::Player(float x, float y, std::string filename, PLAYER s){
	
	_side = s;
	if (_side == left) X(50.0f);
	else X(750.0f);

	x = X();
	Y(y);

	_tex = new Texture(filename,x,y,20,100);
}

Player::~Player() {}

Texture * Player::GetTexture(){

	return _tex;
}

void Player::Update() {

	_tex->UpdateRectXY(Y());
}

void Player::Render() {

	_tex->Render();
}

void Player::MoveUp(){

	_y += -VEL;
	if (_y < 0) _y = 0;
}

void Player::MoveDown() {

	_y += VEL;
	if (_y > 500) _y = 500;
}

void Player::AddScore(){

	score++;
}

std::string Player::Score(){

	return std::to_string(score);
}
