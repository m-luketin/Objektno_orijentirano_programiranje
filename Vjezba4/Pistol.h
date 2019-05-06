#pragma once

#include "Points.h"

class Pistol {
	Position position;
	int capacity;
	int bullets;

public:
	Pistol(int capacity);
	Pistol(Position position, int capacity);
	void Shoot();
	void Reload();
	int Bullets() const;
	Position GetPosition() const;
};