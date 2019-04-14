#pragma once
#include <iostream>

namespace OOP
{
	class Vec3
	{
		int x;
		int y;
		int z;
		static int counter;

public:
		Vec3();
		~Vec3();
		friend std::istream& operator>>(std::istream &input, Vec3 &vector);
		friend std::ostream& operator<<(std::ostream &output, const Vec3 &vector);
		Vec3& operator=(const Vec3 &vector);
		Vec3& operator+(const Vec3 &vector) const;
		Vec3& operator-(const Vec3 &vector) const;
		friend Vec3& operator*(const Vec3 &vector, const int& scalar);
		friend Vec3& operator/(const Vec3 &vector, const int& scalar);
		friend bool operator==(const Vec3 &vector1, const Vec3 &vector2);
		friend bool operator!=(const Vec3 &vector1, const Vec3 &vector2);
		friend int operator*(const Vec3 &vector1, const Vec3 &vector2);
		int operator[](const int index) const;
		int LowestOfThree( int a, int b, int c);
		int HighestCommonDenominator(int a, int b, int c);
		friend void NormalizeVector(Vec3& vector);

	};
}
