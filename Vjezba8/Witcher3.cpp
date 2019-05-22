#include "Witcher3.h"

Witcher3::Witcher3(string platforms)
{
	type = "Open World, Rpg";
	platformsVector = ParseToEnum(platforms);
}

string Witcher3::Type()
{
	return type;
}

vector<platforms>* Witcher3::Platforms()
{
	return &platformsVector;
}
