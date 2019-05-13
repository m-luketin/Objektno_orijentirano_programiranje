#include <iostream>
#include "Vec3.h"

int OOP::Vec3::counter = 0;

OOP::Vec3::Vec3()
{
	x = 0;
	y = 0;
	Vec3::z = 0;
	Vec3::counter++;
}

OOP::Vec3::~Vec3()
{
	delete this;
}

std::istream& OOP::operator>>(std::istream &input, OOP::Vec3 &vector)
{
	input >> vector.x >> vector.y >> vector.z;
	return input;
}

std::ostream& OOP::operator<<(std::ostream &output, const OOP::Vec3 &vector)
{
	output << vector.x << " " << vector.y << " " << vector.z << "\n";
	return output;
}

OOP::Vec3& OOP::Vec3::operator=(const Vec3 &vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;

	return *this;
}

OOP::Vec3& OOP::Vec3::operator+(const Vec3 &vector) const
{
	const auto resultVector = new Vec3();
	resultVector->x = x + vector.x;
	resultVector->y = y + vector.y;
	resultVector->z = z + vector.z;

	return *resultVector;
}


OOP::Vec3& OOP::Vec3::operator-(const Vec3 &vector) const
{
	const auto resultVector = new Vec3();
	resultVector->x = x - vector.x;
	resultVector->y = y - vector.y;
	resultVector->z = z - vector.z;

	return *resultVector;
}

OOP::Vec3& OOP::operator*(const OOP::Vec3 &vector, const int& scalar)
{
	const auto resultVector = new OOP::Vec3();
	resultVector->x = vector.x * scalar;
	resultVector->y = vector.y * scalar;
	resultVector->z = vector.z * scalar;

	return *resultVector;
}

OOP::Vec3& OOP::operator/(const OOP::Vec3 &vector, const int& scalar)
{
	const auto resultVector = new OOP::Vec3();
	resultVector->x = vector.x / scalar;
	resultVector->y = vector.y / scalar;
	resultVector->z = vector.z / scalar;

	return *resultVector;
}

bool OOP::operator==(const OOP::Vec3 &vector1, const OOP::Vec3 &vector2)
{
	return (vector1.x == vector2.x && vector1.y == vector2.y && vector1.z == vector2.z);
}

bool OOP::operator!=(const OOP::Vec3 &vector1, const OOP::Vec3 &vector2)
{
	return (vector1.x != vector2.x && vector1.y != vector2.y && vector1.z != vector2.z);
}

int OOP::operator*(const OOP::Vec3 &vector1, const OOP::Vec3 &vector2)
{
	auto scalarProduct = 0;
	scalarProduct += vector1.x * vector2.x;
	scalarProduct += vector1.y * vector2.y;
	scalarProduct += vector1.z * vector2.z;

	return scalarProduct;
}

int OOP::Vec3::operator[](const int index) const
{
	if(index == 1)
		return x;
	if(index == 2)
		return y;
	if(index == 3)
		return z;

	return 0;
}

int LowestOfThree( int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	if (c <= a && c <= b)
		return c;

	return 0;
}

int HighestCommonDenominator(int a, int b, int c)
{
	auto maxDenominator = 1;
	const auto lowestMember = LowestOfThree(a, b, c);

	for (auto i = 2; i <= lowestMember; i++)
	{
		if(!(a % i) && !(b % i) && !(c % i))
		{
			maxDenominator = i;
		}
	}

	return maxDenominator;
}

void OOP::NormalizeVector(OOP::Vec3& vector)
{
	const auto denominator = HighestCommonDenominator(vector.x, vector.y, vector.z);

	vector.x /= denominator;
	vector.y /= denominator;
	vector.z /= denominator;
}