#include <iostream>

using namespace std;

const int init = 10;

struct fake_vector
{
	int* array;
	int allocated;
	int size;
};


fake_vector* vector_new(int allocation_size)
{
	fake_vector* vector = new fake_vector;

	if (!allocation_size) {
		vector->array = new int[init];
		vector->allocated = init;
	}
	else {
		vector->array = new int[allocation_size];
		vector->allocated = allocation_size;
	}

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

void double_allocated_memory(fake_vector* vector)
{
	fake_vector* tmp_vector = vector_new(vector->allocated * 2);

	for (int i = 0; i < vector->size; i++)
	{
		tmp_vector->array[i] = vector->array[i];
	}

	tmp_vector->size = vector->size;
	tmp_vector->allocated = vector->allocated * 2;
	vector_delete(vector);
	vector = tmp_vector;
	vector_delete(tmp_vector);
}

void vector_push_back(fake_vector* vector, int number_to_push)
{
	if (vector->size == vector->allocated)
		double_allocated_memory(vector);

	vector->array[vector->size] = number_to_push;
	vector->size++;
}

int* vector_pop_back(fake_vector* vector)
{
	vector->size--;
	return &(vector->array[vector->size]);
}

void vector_print(fake_vector* vector)
{
	for (int i = 0; i < vector->size; i++)
		cout << vector->array[i] << " ";
	cout << "\n";
}

int main()
{
	fake_vector *vector = vector_new(NULL);

	vector_push_back(vector, 1);
	vector_push_back(vector, 2);
	vector_push_back(vector, 7);
	vector_push_back(vector, 9);
	vector_push_back(vector, 3);
	vector_push_back(vector, 5);
	vector_push_back(vector, 4);
	vector_push_back(vector, 6);
	vector_push_back(vector, 8);
	vector_push_back(vector, 10);

	vector_print(vector);
	cout << "Vector size: " << vector_size(vector) << "\n";
	cout << "Vector_front: " << *vector_front(vector) << "\n";
	cout << "Vector_back: " << *vector_back(vector) << "\n\n";

	cout << "Popped " << *vector_pop_back(vector) << " out\n";
	cout << "Popped " << *vector_pop_back(vector) << " out\n\n";

	vector_print(vector);
	cout << "Vector size: " << vector_size(vector) << "\n";
	cout << "Vector_front: " << *vector_front(vector) << "\n";
	cout << "Vector_back: " << *vector_back(vector) << "\n\n";

	vector_delete(vector);
	system("pause");
}