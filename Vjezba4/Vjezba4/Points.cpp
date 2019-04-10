#include "Points.h"
#include <iostream>

Position::Position()
{
	x = 0;
	y = 0;
	z = 0;
}

Position::Position(const double width = 0, const double length = 0, const double height = 0)
{
	x = width;
	y = length;
	z = height;
}

void Position::SetRandomPosition(const int lowerLimit, const int higherLimit)
{
	x = rand() % (higherLimit - lowerLimit) + double(lowerLimit);
	y = rand() % (higherLimit - lowerLimit) + double(lowerLimit);
	z = rand() % (higherLimit - lowerLimit) + double(lowerLimit);
}

void Position::PrintPosition() const
{
	std::cout << Position::x << " " << Position::y << " " << Position::z << "\n";
}

double Position::GetWidth() const
{
	return x;
}

double Position::GetLength() const
{
	return y;
}

double Position::GetHeight() const
{
	return z;
}

double Position::Distance(const Position otherPosition, const int dimensions) const
{
	if (dimensions == 2 || dimensions == 3) 
	{
		const auto squaredWidth = pow((x - otherPosition.x), 2);
		const auto squaredLength = pow((y - otherPosition.y), 2);
		auto squaredHeight = 0.0;

		if (dimensions == 3) 
			squaredHeight = pow((z - otherPosition.z), 2);
		
		return sqrt(squaredHeight + squaredLength + squaredWidth);
	}
	return 0;
}
