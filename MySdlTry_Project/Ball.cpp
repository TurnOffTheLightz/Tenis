#include "Ball.h"

Texture * Ball::GetTexture(){

	return _tex;
}

void Ball::Update(Player *p1,Player *p2){

	if (!_shoot) {

		if (_leftStarts) {

			_x = p1->X()+21;
			_y = p1->Y()+30;
		}
		else {

			_x = p2->X()-56;
			_y = p2->Y()+30;
		}
	}
	else {

		ProcessMovement(p1,p2);
	}
	if (_shootMoment) {

		_shootMoment = false;
		RandVec();
	}

	_tex->UpdateRectXY(_x,_y);
}

void Ball::Render(){

	_tex->Render();
}

void Ball::ProcessMovement(Player *p1, Player *p2){

	if (ticks % 3 == 0) {

		_x += _vx;
		_y += _vy;
		if (_y < 0 || _y > 545) {
			_vy = -_vy;
		}
		if (_x < 0) {
			p2->AddScore();
			Reset();
		}
		else if (_x > 745) {
			p1->AddScore();
			Reset();
		}
	}
	ticks++;
}

void Ball::Reset(){

	_leftStarts = !_leftStarts;
	_shoot = false;
	ticks = 0;
}


void Ball::Shoot(bool x){

	_shoot = x;
	_shootMoment = x;
}
bool Ball::Shoot() {

	return _shoot;
}

void Ball::RandVec(){

		if (_leftStarts) {

			_vx = (rand() % 9 + 7) / 1000.0f;
		}
		else {

			_vx = -(rand() % 9 + 7) / 1000.0f;
		}
		_vy = (rand() % 30 - 10) / 1000.0f;
}

void Ball::ReverseVX(){

	_vx = -_vx;
}

float Ball::VX(){

	return _vx;
}

float Ball::VY() {

	return _vy;
}

Ball::Ball(float x, float y, std::string filename){

	X(x);
	Y(y);

	_tex = new Texture(filename, x, y, 55, 55);

	srand(time(NULL));
}

Ball::Ball(){

}

Ball::~Ball(){

}
