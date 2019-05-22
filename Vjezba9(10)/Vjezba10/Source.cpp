#include "Zbroj.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	Zbroj<int> objekt(2,3);
	
	cout << objekt.Zbroji();
	
	system("pause");
}
