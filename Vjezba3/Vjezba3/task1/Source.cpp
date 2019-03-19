#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

vector<int> VectorInput(bool randGen, int a = 0, int b = 100, int n = 5)
{
	int vectorElement;
	vector<int> vector;

	for (int i = 0; i < n; i++) {
		if (randGen)
			vectorElement = rand() % (b - a) + a; //generates random element between a and b
		else
		{
			cout << "Enter element value:\n";
			cin >> vectorElement;

			while (vectorElement < a || vectorElement > b) {
				cout << "Element must be from given interval!\n";
				cin >> vectorElement;
			}
		}
		vector.push_back(vectorElement);
	}
	return vector;
}

void PrintVector(vector<int> vector)
{
	cout << "Vector: ";
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i] << " ";
	cout << "\n";
}

int main()
{
	srand(time(NULL));
	vector<int> vector = VectorInput(true);

	PrintVector(vector);

	system("pause");
}