#include "VideoGame.h"
#include <iostream>
#include <vector>
#include "GodOfWar.h"
#include "DarkSouls.h"
#include "Fallout4.h"
#include "LastOfUs2.h"
#include "Witcher3.h"

using namespace std;

int main()
{
	auto videoGames = new vector<VideoGame*>;
	
	videoGames->push_back(new GodOfWar);
	videoGames->push_back(new DarkSouls);
	videoGames->push_back(new Fallout4);
	videoGames->push_back(new LastOfUs2);
	videoGames->push_back(new Witcher3);


	system("pause");
}