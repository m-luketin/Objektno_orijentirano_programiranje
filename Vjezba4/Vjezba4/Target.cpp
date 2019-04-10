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

Target::Target(Position position, int width, int height)
{
	position = position;
	width = width;
	height = height;
	hit = false;
}

void Target::Hit() 
{
	hit = true;
}

bool Target::IsHit() {
	return hit;
}

Position Target::GetPosition()
{
	return position;
}

int Target::GetHeight()
{
	return height;
}