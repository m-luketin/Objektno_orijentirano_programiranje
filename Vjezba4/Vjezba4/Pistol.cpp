#include "Pistol.h"
#include <iostream>

Pistol::Pistol(int gunCapacity) 
{
	Position gunPosition;
	gunPosition.SetRandomPosition(-100, 100);
	position = gunPosition;
	capacity = gunCapacity;
	bullets = 0;
}

Pistol::Pistol(Position	gunPosition, int gunCapacity)
{
	capacity = gunCapacity;
	bullets = 0;
	position = gunPosition;
}

void Pistol::Shoot()
{
	if (bullets) 
	{
		bullets--;
		std::cout << "Shot!\n";
	}
	else
		std::cout << "No bullets left!\n";
}

void Pistol::Reload()
{
	bullets = capacity;
	std::cout << "Reloaded!\n";
}

int Pistol::Bullets()
{
	return bullets;
}

Position Pistol::GetPosition()
{
	return position;
}