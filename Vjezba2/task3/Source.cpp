#include <iostream>

using namespace std;

const int init = 10;

struct fake_vector
{
	int array[init];
	int allocated;
	int size;
};


fake_vector* vector_new()
{
	fake_vector* vector = new fake_vector;
	vector->allocated = init;
	vector->size = 0;

	return vector;
}

void vector_delete(fake_vector* vector)
{
	delete[] vector->array;
	delete vector;
}

int vector_size(fake_vector* vector)
{
	return vector->size;
}

int* vector_front(fake_vector* vector)
{
	return (&(vector->array[0]));
}

int* vector_back(fake_vector* vector)
{
	return (&(vector->array[vector->size - 1]));
}

int main()
{
	fake_vector *vector = vector_new();

	cout << "Vector size: " << vector_size(vector) << "\n";

	int* first_number = vector_front(vector);
	cout << "Vector_front: " << *first_number << "\n";

	int* last_number = vector_back(vector);
	cout << "Vector_back: " << *last_number << "\n";


	vector_delete(vector);
	system("pause");
}