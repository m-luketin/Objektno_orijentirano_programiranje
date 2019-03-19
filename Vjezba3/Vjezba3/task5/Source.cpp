#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producer {
	string name;
	string movie;
	int year;
};

vector<Producer> FillProducerVector(vector<Producer> vector, int producersToAdd)
{
	Producer producer;
	for (int i = 0; i < producersToAdd; i++) {
		cout << "Enter producer name:\n";
		cin >> producer.name;
		cout << "Enter movie name:\n"; 
		cin >> producer.movie;
		cout << "Enter year:\n";
		cin >> producer.year;
		vector.push_back(producer);
	}
	return vector;
}

string MostRepresentedProducer(vector<Producer> vector)
{
	string maxName, tmpName;
	int maxCounter = 0, tmpCounter = 0;

	for (int i = 0; i < vector.size(); i++)
	{
		tmpName = vector[i].name;
		for (int j = 0; j < vector.size(); j++)
			if (tmpName == vector[j].name)
				tmpCounter++;

		if (tmpCounter > maxCounter)
		{
			maxName = tmpName;
			maxCounter = tmpCounter;
		}
		tmpCounter = 0;
	}
	return maxName;
}

int main()
{
	int producersToAdd = 4;
	vector<Producer> vector;
	vector = FillProducerVector(vector, producersToAdd);

	cout << MostRepresentedProducer(vector) << "\n";

	system("pause");
}