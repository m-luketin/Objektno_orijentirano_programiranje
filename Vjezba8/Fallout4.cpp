#include "Fallout4.h"

Fallout4::Fallout4(string platforms)
{
	type = "Rpg";
	platformsVector = ParseToEnum(platforms);
}