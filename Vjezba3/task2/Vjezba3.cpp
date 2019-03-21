#include "Vjezba3.h"

using namespace std;


vector<int> VectorDifference(vector<int> firstVector, vector<int> secondVector)
{
	vector<int> newVector;
	for (int i = 0; i < firstVector.size(); i++) {
		if (!binary_search(secondVector.begin(), secondVector.end(), firstVector[i]))
			newVector.push_back(firstVector[i]);
	}
	return newVector;
}