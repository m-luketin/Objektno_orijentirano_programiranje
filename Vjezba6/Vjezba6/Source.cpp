#include "Vec3.h"



int main()
{
	OOP::Vec3 vector1, vector2;

	std::cin >> vector1;
	std::cout << "Vector1: ";
	std::cout << vector1;

	std::cin >> vector2;
	std::cout << "Vector2: ";
	std::cout << vector2;

	const auto resultVector = vector1;
	std::cout << "Vector1 copied: ";
	std::cout << resultVector;

	std::cout << "Vector1 + Vector2: ";
	std::cout << vector1 + vector2;

	std::cout << "Vector1 - Vector2: ";
	std::cout << vector1 - vector2;

	std::cout << "Vector1 * 3: ";
	std::cout << vector1 * 3;

	std::cout << "Vector1 / 2: ";
	std::cout << vector1 / 2;

	std::cout << "Vector1 * Vector2: ";
	std::cout << vector1 * vector2 << "\n";

	std::cout << "Vector1[1]: ";
	std::cout << vector1[1] << "\n";

	std::cout << "Normalized Vector1: ";
	NormalizeVector(vector1);
	std::cout << vector1 << "\n";

	system("pause");
}