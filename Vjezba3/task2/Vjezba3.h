#ifndef VJEZBA3_H
#define VJEZBA3_H

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

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

#endif