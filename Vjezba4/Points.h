#pragma once

class Position
{
	double x;
	double y;
	double z;

public:
	Position();

	Position(const double x, const double y, const double z);

	void SetRandomPosition(const int lowerLimit, const int higherLimit);

	void PrintPosition() const;

	double GetWidth() const;

	double GetLength() const;

	double GetHeight() const;

	double Distance(const Position otherPosition, const int dimensions) const;
};