#include "Points.h"
#include <random>
#include <iostream>

Position::Position()
{
	x = 0;
	y = 0;
	z = 0;
}

Position::Position(double width = 0, double length = 0, double height = 0)
{
	x = width;
	y = length;
	z = height;
}

void Position::SetRandomPosition(int lowerLimit, int higherLimit)
{
	x = rand() % (higherLimit - lowerLimit) + lowerLimit;
	y = rand() % (higherLimit - lowerLimit) + lowerLimit;
	z = rand() % (higherLimit - lowerLimit) + lowerLimit;
}

void Position::PrintPosition()
{
	std::cout << Position::x << " " << Position::y << " " << Position::z << "\n";
}

double Position::GetWidth()
{
	return x;
}

double Position::GetLength()
{
	return y;
}

double Position::GetHeight()
{
	return z;
}

double Position::Distance(Position otherPosition, int dimensions)
{
	if (dimensions == 2 || dimensions == 3) 
	{
		double squaredWidth = pow((x - otherPosition.x), 2);
		double squaredLength = pow((y - otherPosition.y), 2);
		double squaredHeight = 0;

		if (dimensions == 3) 
			double squaredHeight = pow((z - otherPosition.z), 2);
		
		return sqrt(squaredHeight + squaredLength + squaredWidth);
	}
	return 0;
}
