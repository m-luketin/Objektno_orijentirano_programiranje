#include <iostream>
#include <algorithm>

using namespace std;

int* new_array(int array_size) 
{
	int *array = new int[array_size];

	cout << "Enter array elements:\n";
	for (int i = 0; i < array_size - 1; ++i)
		cin >> array[i];

	array[array_size - 1] = 0;
	return array;
}

bool is_number_in_array(int* array, int array_size, int number_for_search)
{
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] == number_for_search)
			return true;
	}
	return false;
}

int* add_missing_element(int* array, int array_size) 
{
	for (int i = 1; i < array_size; i++)
	{
		if (!is_number_in_array(array, array_size, i))
		{
			array[array_size - 1] = i;
			break;
		}
	}

	sort(array, array + array_size);
	return array;
}

int main()
{
	int size_of_array = 9;
	int* array = new_array(size_of_array);
	
	cout << "\nEntered array:\n";
	for (int i = 0; i < size_of_array - 1; i++) 
	{
		cout << array[i] << " ";
	}
	cout << "\n";

	sort(array, array + size_of_array - 1);

	array = add_missing_element(array, size_of_array);

	cout << "\nSorted with missing element:\n";
	for (int i = 0; i < size_of_array; i++) 
	{
		cout << array[i] << " ";
	}
	cout << "\n";

	delete[] array;
	system("pause");
}