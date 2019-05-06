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
	Target(const Position position, const int width, const int height);
	void Hit();
	bool IsHit() const;
	Position GetPosition() const;
	int GetHeight() const;
};