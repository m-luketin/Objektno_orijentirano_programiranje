#include <iostream>

using namespace std;

const int init = 8;

struct fake_vector
{
	int* array;
	int allocated;
	int size;

	void vector_new(int allocation_size)
	{
		fake_vector* vector = new fake_vector;

		if (!allocation_size) {
			array = new int[init];
			allocated = init;
		}
		else {
			array = new int[allocation_size];
			allocated = allocation_size;
		}

		size = 0;
	}

	void vector_delete()
	{
		delete[] array;
		size = NULL;
		allocated = NULL;
	}

	int vector_size()
	{
		return size;
	}

	int* vector_front()
	{
		return array;
	}

	int* vector_back()
	{
		return (&array[size - 1]);
	}

	void double_allocated_memory()
	{
		int* tmp_array = new int[allocated];

		for (int i = 0; i < size; i++)
			tmp_array[i] = this->array[i];

		delete[] array;
		array = new int[allocated * 2];

		for (int i = 0; i < size; i++)
			this->array[i] = tmp_array[i];

		delete[] tmp_array;
	}

	void vector_push_back(int number_to_push)
	{
		if (size == allocated)
			this->double_allocated_memory();

		array[size] = number_to_push;
		size++;
	}

	int* vector_pop_back()
	{
		size--;
		return &array[size];
	}

	void vector_print()
	{
		for (int i = 0; i < size; i++)
			cout << array[i] << " ";
		cout << "\n";
	}
};

int main()
{
	fake_vector vector;
	vector.vector_new(NULL);

	int tmp;
	for (int i = 0; i < vector.allocated; i++)
	{
		cin >> tmp;
		vector.vector_push_back(tmp);
	}

	vector.vector_print();
	cout << "Vector size: " << vector.vector_size() << "\n";
	cout << "Vector_front: " << *vector.vector_front() << "\n";
	cout << "Vector_back: " << *vector.vector_back() << "\n\n";

	vector.vector_push_back(20);
	vector.vector_print();
	cout << "Vector size: " << vector.vector_size() << "\n";
	cout << "Vector_front: " << *vector.vector_front() << "\n";
	cout << "Vector_back: " << *vector.vector_back() << "\n\n";

	cout << "Popped " << vector.vector_pop_back() << " out\n";
	cout << "Popped " << vector.vector_pop_back() << " out\n\n";

	vector.vector_print();
	cout << "Vector size: " << vector.vector_size() << "\n";
	cout << "Vector_front: " << *vector.vector_front() << "\n";
	cout << "Vector_back: " << *vector.vector_back() << "\n\n";

	vector.vector_delete();
	system("pause");
}