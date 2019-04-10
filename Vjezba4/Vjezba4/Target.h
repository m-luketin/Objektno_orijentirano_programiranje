#pragma once

#include "Points.h"

class Target
{
	Position position;
	int width;
	int height;
	bool hit;

public:
	Target();
	Target(Position position, int width, int height);
	void Hit();
	bool IsHit();
	Position GetPosition();
	int GetHeight();
};