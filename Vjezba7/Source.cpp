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
	auto *gavrilovic = new Ham(10, 0, "Meat", "Ham", 20, 30, 40, 17, "10-10-2019", 50 );
	auto *disgusting = new Tofu(15, 0, "Veggie", "Tofu", 10, 15, 40, 10, "07-11-2019", 20);
	auto *zbregov = new Yoghurt(20, 0, "Dairy", "Yoghurt", 5, 55, 45, 20, "27-04-2020", 10);
	auto *ferrero = new Cake(20, "Sweets", "Cake", 5, 55, 45, 20, "27-04-2018", 10);

	auto foodVector = new vector<Food*>;
	
	foodVector->push_back(gavrilovic);
	foodVector->push_back(disgusting);
	foodVector->push_back(zbregov);
	foodVector->push_back(ferrero);

	for (auto i = 0; i < 4; i++)
	{
		cout << *(Meat*)(foodVector->at(i));		
	}
	

	system("pause");
}