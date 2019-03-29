#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include"SDL.h"

class Collision {
public:

	static bool Intersects(const SDL_Rect& recA, const SDL_Rect &recB);
public:
};

#endif