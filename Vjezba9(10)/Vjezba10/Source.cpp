#include "Zbroj.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	Zbroj<int> objekt(2,3);
	Zbroj<char> objektDrugi('a', 'c');

	cout << objekt.Zbroji() << endl;
	cout << objektDrugi.Zbroji() << endl;

	system("pause");
}
