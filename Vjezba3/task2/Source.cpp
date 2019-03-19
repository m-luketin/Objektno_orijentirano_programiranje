#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

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

vector<int> VectorDifference(vector<int> firstVector, vector<int> secondVector)
{
	vector<int> newVector;
	for (int i = 0; i < firstVector.size(); i++) {
		if (!binary_search(secondVector.begin(), secondVector.end(), firstVector[i]))
			newVector.push_back(firstVector[i]);
	}
	return newVector;
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