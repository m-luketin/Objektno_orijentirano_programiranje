#include "Food.h"
#include <vector>

using namespace std;

int main()
{
	vector<Food> foodVector;

	Food beef("meat", "beef", 10, 50, 20, 10, "10-08-2019", 50);
	Food lettuce("veggies", "lettuce", 100, 0, 0, 0, "10-11-2019", 20);
	Food italiana("pasta", "italiana", 0, 0, 20, 80, "20-12-2019", 20);
	Food pizza("junk", "pizza", 10, 20, 20, 50, "01-07-2019", 20);
	Food croissant("pastries", "croissant", 0, 0, 20, 80, "30-09-2019", 20);

	beef.RandomizeMonthlySpending();
	lettuce.RandomizeMonthlySpending();
	italiana.RandomizeMonthlySpending();
	pizza.RandomizeMonthlySpending();

	foodVector.push_back(beef);
	foodVector.push_back(lettuce);
	foodVector.push_back(italiana);
	foodVector.push_back(pizza);

	croissant.EnterMonthlySpending();
	foodVector.push_back(croissant);

	for (auto& i : foodVector)
		i.Print();

	lettuce.DailyChange(lettuce.CalculateSpendingChange());

	system("pause");
}