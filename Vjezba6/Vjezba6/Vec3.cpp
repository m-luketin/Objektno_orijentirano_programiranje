#include <istream>
#include "Vec3.h"


std::istream& operator >>(std::istream &input, Vec3 vector)
{
	input >> vector.x;
	input >> vector.y;
	input >> vector.z;

	return input;
}
