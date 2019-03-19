#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int CountMatches(vector<bool> vector)
{
	int counter = 0;
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i] == true)
			counter++;
	}
	return counter;
}

bool WinState(vector<bool> vector)
{
	int flag = 0;
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i] == true)
			flag++;
	}
	return (flag == 1);
}

void MakeMove(vector<bool> *vector, int numberOfMatches)
{
	int i = 0;
	while ((*vector)[i] == false) //sets i to first match found
		i++;

	for (int limit = i + numberOfMatches; i < limit; i++) //makes the move
		(*vector)[i] = false;
}

bool ComputerMove(vector<bool> *matches)
{
	int nextWinPosition = (CountMatches(*matches) - 2) / 4 * 4 + 1; //calculates the next winning position(5,9,13,17)
	int matchesToRemove = CountMatches(*matches) - nextWinPosition;
	if (matchesToRemove > 3)
		matchesToRemove = rand() % 3 + 1; // if computer cant get to winning position, random move

	MakeMove(matches, matchesToRemove);
	cout << "Computer removed " << matchesToRemove << " matches\n";

	if (WinState(*matches)) {
		cout << "Computer won!\n";
		return true;
	}
	return false;
}

bool PlayerMove(vector<bool> *matches)
{
	int matchesToRemove;
	cout << "Current number of matches: " << CountMatches(*matches) << "\n" << "How many matches would you like to remove?\n";
	cin >> matchesToRemove;

	while (matchesToRemove != 1 && matchesToRemove != 2 && matchesToRemove != 3)
	{
		cout << "Bad input! Try again!";
		cin >> matchesToRemove;
	}

	MakeMove(matches, matchesToRemove);

	if (WinState(*matches)) {
		cout << "Player won!\n";
		return true;
	}
	return false;
}

int main()
{
	vector<bool> matches;
	srand(time(NULL));

	for (int i = 0; i < 21; i++)
		matches.push_back(true);

	while (true)
	{
		if (ComputerMove(&matches))
			break;

		if (PlayerMove(&matches))
			break;
	}

	system("pause");
}