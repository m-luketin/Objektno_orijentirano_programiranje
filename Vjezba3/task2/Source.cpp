#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

#include "Vjezba3.h"

using namespace std;

vector<int> VectorInput(bool randGen, int a = 0, int b = 100, int n = 5)
{
	int vectorElement;
	vector<int> vector;
	b = 30;

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
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i] << " ";
	cout << "\n";
}

int main()
{
	srand(time(NULL));
	vector<int> firstVector = VectorInput(true);
	vector<int> secondVector = VectorInput(true);
	
	sort(firstVector.begin(), firstVector.end());
	sort(secondVector.begin(), secondVector.end());

	PrintVector(firstVector);
	PrintVector(secondVector);

	vector<int> differenceOfVectors = VectorDifference(firstVector, secondVector);
	PrintVector(differenceOfVectors);

	system("pause");
}