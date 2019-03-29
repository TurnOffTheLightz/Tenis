#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include<string>

class Entity {

protected:

	float _x;
	float _y;
	std::string _filename;


public:

	float X();
	float Y();
	void X(float x);
	void Y(float y);



	virtual void Update();
	virtual void Render(); 
public:

	Entity();
	Entity(float x, float y, std::string filename);
	virtual ~Entity();
};

#endif