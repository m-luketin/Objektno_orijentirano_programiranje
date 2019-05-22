#include "DarkSouls.h"

DarkSouls::DarkSouls(string platforms)
{
	type = "Rpg";
	platformsVector = ParseToEnum(platforms);
}
