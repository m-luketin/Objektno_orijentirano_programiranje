#include "VideoGame.h"
#include <iostream>
#include <vector>
#include "GodOfWar.h"
#include "DarkSouls.h"
#include "Fallout4.h"
#include "LastOfUs2.h"
#include "Witcher3.h"
#include "Counter.h"
#include <fstream>

using namespace std;

int main()
{
	vector<string> gamePlatformStrings;
	ifstream myReadFile;
	myReadFile.open("videogames.txt");
	string output;
	string temp;

	while (!myReadFile.eof()) 
	{
		myReadFile >> output;
		cout << output << endl;
		auto i = 0;
		for (; output[i] != '#'; ++i);
		for (; i < output.length(); ++i)
			temp.push_back(output[i]);

		gamePlatformStrings.push_back(temp);
	}
	cout << endl;

	auto videoGames = new vector<Game*>;
	
	videoGames->push_back(new Witcher3(gamePlatformStrings.back()));
	gamePlatformStrings.pop_back();
	videoGames->push_back(new LastOfUs2(gamePlatformStrings.back()));
	gamePlatformStrings.pop_back();
	videoGames->push_back(new GodOfWar(gamePlatformStrings.back()));
	gamePlatformStrings.pop_back();
	videoGames->push_back(new Fallout4(gamePlatformStrings.back()));
	gamePlatformStrings.pop_back();
	videoGames->push_back(new DarkSouls(gamePlatformStrings.back()));
	gamePlatformStrings.pop_back();

	Counter counter;

	for(auto i = videoGames->begin(); i != videoGames->end(); ++i)
	{
		counter.TypeOfGame(**i);
	}
	cout << "The most represented platform is: ";
	counter.PrintMax();

	system("pause");
}