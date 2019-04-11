#include <iostream>
#include "Food.h"
#include <vector>

using namespace std;

int main()
{
	vector<Food> foodVector;

	Food beef("meat", "beef", 10, 50, 20, 10, "10-08-2019", 50);
	Food lettuce("veggies", "tomato", 100, 0, 0, 0, "10-11-2019", 20);
	Food italiana("pasta", "italiana", 0, 0, 20, 80, "20-12-2019", 20);
	Food pizza("junk", "pizza", 10, 20, 20, 50, "01-07-2019", 20);
	Food croissant("pastries", "croissant", 0, 0, 20, 80, "30-04-2019", 20);

	beef.EnterMonthlySpending();
	lettuce.EnterMonthlySpending();
	italiana.EnterMonthlySpending();
	pizza.EnterMonthlySpending();
	croissant.EnterMonthlySpending();

	foodVector.push_back(beef);
	foodVector.push_back(lettuce);
	foodVector.push_back(italiana);
	foodVector.push_back(pizza);
	foodVector.push_back(croissant);
	
	for (auto& i : foodVector)
		i.Print();

	system("pause");
}