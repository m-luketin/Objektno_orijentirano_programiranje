#include <iostream>
#include <vector>
#include "Food.h"
#include "Ham.h"
#include "Tofu.h"
#include "Yoghurt.h"
#include "Cake.h"

using namespace std;

int main()
{
	auto ham = new Ham(10, 0, "Meat", "Ham", 20, 30, 40, 17, "10-10-2019", 50 );
	auto tofu = new Tofu(15, 0, "Veggie", "Tofu", 10, 15, 40, 10, "07-11-2019", 20);
	auto yoghurt = new Yoghurt(0, 0, "Dairy", "Yoghurt", 5, 55, 45, 20, "27-04-2020", 10);
	auto cake = new Cake(20, "Sweets", "Cake", 5, 55, 45, 20, "27-04-2018", 10);

	auto foodVector = *new vector<Food*>;
	
	foodVector.push_back(ham);
	foodVector.push_back(tofu);
	foodVector.push_back(yoghurt);
	foodVector.push_back(cake);

	for (auto i = foodVector.begin(); i != foodVector.end(); i++)
	{
		cout << **i;		
	}

	delete yoghurt;
	delete tofu;
	delete ham;
	delete cake;
	system("pause");
}