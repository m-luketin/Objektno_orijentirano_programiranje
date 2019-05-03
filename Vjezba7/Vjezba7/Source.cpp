#include <iostream>
#include <vector>
#include "Food.h"
#include "Ham.h"
#include "Tofu.h"
#include "Yoghurt.h"

using namespace std;

int main()
{
	auto foodVector = new vector<Food>;
	
	Ham gavrilovic(10, 0, "Meat", "Ham", 20, 30, 40, 17, "10-10-2019", 50 );
	Tofu disgusting(15, 0, "Veggie", "Tofu", 10, 15, 40, 10, "07-11-2019", 20);
	Yoghurt zbregov(20, 0, "Dairy", "Yoghurt", 5, 55, 45, 20, "27-04-2020", 10);

	foodVector->push_back(gavrilovic);

	system("pause");
}