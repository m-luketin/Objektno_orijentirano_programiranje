#pragma once

class Position
{
	double x;
	double y;
	double z;

public:
	Position();

	Position(double x, double y, double z);

	void SetRandomPosition(int lowerLimit, int higherLimit);

	void PrintPosition();

	double GetWidth();

	double GetLength();

	double GetHeight();

	double Distance(Position otherPosition, int dimensions);
};