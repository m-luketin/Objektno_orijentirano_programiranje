#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

bool ProperInput(string stringInput)
{
	if (stringInput.length() > 20)
		return false;

	for (int i = 0; i < stringInput.length(); i++) {
		if (islower(stringInput[i]) || !(isalpha(stringInput[i]) || isdigit(stringInput[i]))) //if input is lowercase or not a digit/letter
			return false;
	}

	return true;
}

vector<string> InitializeVector()
{
	int N;
	string tmpString;
	vector<string> vector;

	cout << "Enter number of strings:\n";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cout << "Enter string:\n";
		cin >> tmpString;
		if (!ProperInput(tmpString))
		{
			cout << "Bad input! Try again.\n";
			i--;
		}
		else
			vector.push_back(tmpString);
	}
	return vector;
}

bool SelectOperation(string stringToTransform) //letters to numbers returns true, numbers to letters returns false
{
	for (int i = 0; i < stringToTransform.length(); i++) {
		if (isdigit(stringToTransform[i]))
			return false;
	}
	return true;
}

string LettersToNumbers(string stringToTransform)
{
	int letterCounter = 1;
	string newString = "";

	for (int i = 1; i < stringToTransform.length(); i++)
	{
		if (stringToTransform[i] != stringToTransform[i - 1]) //counts until different letter, then save
		{
			if (letterCounter != 1)
				newString += (char)letterCounter + 48;

			newString += stringToTransform[i - 1];
			letterCounter = 1;
		}
		else
			letterCounter++;

		if (i == stringToTransform.length() - 1) //handling final letter
		{
			if (letterCounter != 1)
				newString += (char)letterCounter + 48;

			newString += stringToTransform[i];
		}
	}
	return newString;
}

string NumbersToLetters(string stringToTransform)
{
	string newString = "";

	for (int i = 0; i < stringToTransform.length(); i++)
	{
		if (isdigit(stringToTransform[i]))
		{
			for (int j = 0; j < (int)stringToTransform[i] - 48; j++)
				newString += stringToTransform[i + 1];

			i++;
		}
		else
			newString += stringToTransform[i];
	}
	return newString;
}

string TransformString(string stringToTransform)
{
	char tmpChar;
	int charCounter = 1;
	string newString = "";

	if (SelectOperation(stringToTransform))
		newString = LettersToNumbers(stringToTransform);
	else
		newString = NumbersToLetters(stringToTransform);

	return newString;
}

int main()
{
	vector<string> vector = InitializeVector();

	cout << "Transformed strings: \n";
	for (int i = 0; i < vector.size(); i++)
	{
		cout << TransformString(vector[i]) << "\n";
	}

	system("pause");
}