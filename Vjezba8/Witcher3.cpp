#include "Witcher3.h"
#include <iostream>

Witcher3::Witcher3()
{
	type = "Open World, Rpg";
	platformsVector = { PS4 };
}

string Witcher3::Type()
{
	return type;
}

vector<VideoGame::platforms> Witcher3::Platforms()
{
	return platformsVector;
}
