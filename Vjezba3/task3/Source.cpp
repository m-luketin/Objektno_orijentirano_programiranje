#include <iostream>
#include <string>

using namespace std;

string RepairInterpunction(string sentence)
{
	string newSentence = "";
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ' && (sentence[i + 1] == ',' || sentence[i + 1] == '.')) //repairs space before interpunction
			continue;

		newSentence += sentence[i];

		if(sentence[i] == ',' && sentence[i + 1] != ' ') //repairs space after interpunction
			newSentence += ' ';
	}
	return newSentence;
}

int main()
{
	string sentence = "I would ,if I can , write this correctly .";

	sentence = RepairInterpunction(sentence);
	cout << sentence << "\n";

	system("pause");
}