#include <iostream>
#include "Food.h"
#include <vector>
#include <map>

using namespace std;

int main()
{
	auto foodVector = new vector<Food>;

	Food beef("meat", "beef", 10, 50, 20, 10, "10-02-2019", 50);
	Food lettuce("veggies", "tomato", 100, 0, 0, 0, "10-06-2019", 20);
	Food italiana("pasta", "italiana", 0, 0, 20, 80, "20-09-2020", 20);
	Food pizza("junk", "pizza", 10, 20, 20, 50, "01-07-2019", 20);
	Food croissant("pastries", "croissant", 0, 0, 20, 80, "30-04-2019", 20);

	foodVector->push_back(beef);
	foodVector->push_back(lettuce);
	foodVector->push_back(italiana);
	foodVector->push_back(pizza);
	foodVector->push_back(croissant);

	for (unsigned int i = 0; i < foodVector->capacity() - 1; i++)
	{
		foodVector->at(i).Print();
	}

	system("pause");
}