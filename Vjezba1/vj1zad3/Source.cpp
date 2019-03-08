#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int& find_number(int *array, int n) {
	for (int i = 0; i < n; i++)
	{
		if ((array[i] % 10) + (array[i] % 1000 / 100) == 5)
			return array[i];
	}
}

int main() {
	const int size_of_array = 8;
	int array[size_of_array] = { 1000, 4957, 1039, 4960, 3960, 1312, 6048, 1694 };

	int &number = find_number(array, size_of_array);

	number++;
	cout << number << "\n";

	system("pause");
}