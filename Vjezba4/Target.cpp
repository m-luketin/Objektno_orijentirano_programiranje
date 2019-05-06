#include "Target.h"
#include <random>

Target::Target()
{
	Position targetPosition;
	targetPosition.SetRandomPosition(-50, 50);
	position = targetPosition;
	width = rand() % 50;
	height = rand() % 50;
	hit = false;
}

Target::Target(const Position targetPosition, const int targetWidth, const int targetHeight)
{
	position = targetPosition;
	width = targetWidth;
	height = targetHeight;
	hit = false;
}

void Target::Hit() 
{
	hit = true;
}

bool Target::IsHit() const
{
	return hit;
}

Position Target::GetPosition() const
{
	return position;
}

int Target::GetHeight() const
{
	return height;
}