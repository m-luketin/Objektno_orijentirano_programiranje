#pragma once
#include <iostream>

class Vec3
{
	int x;
	int y;
	int z;

public:
	std::istream &operator >>(std::istream &input, Vec3 vector);
};
