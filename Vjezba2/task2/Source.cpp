#include <iostream>

using namespace std;

int* new_array(int array_size)
{
	int *array = new int[array_size];
	
	cout << "Enter array elements:\n";
	for (int i = 0; i < array_size; ++i)
		cin >> array[i];
	
	
	return array;
}

bool is_odd(int* n) 
{
	return(*n % 2);
}

bool is_even(int* n)
{
	return(!(*n % 2));
}

void swap(int* a, int* b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int* array, int array_size)
{
	for (int i = 0; i < array_size; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
}

void parity_sort(int* array, int array_size) 
{
	int *start = array, *end = array + array_size - 1;

	while (start != end + 1) 
	{
		if (is_odd(start) && is_even(end))
			swap(start, end);

		while(is_even(start))
			start++;

		while(is_odd(end))
			end--;
	}
}
int main() 
{
	int size_of_array = 8;
	int* array = new_array(size_of_array);

	parity_sort(array, size_of_array);

	print(array, size_of_array);

	delete[] array;
	system("pause");
}