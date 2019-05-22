#include "GodOfWar.h"

GodOfWar::GodOfWar(string platforms)
{
	type = "Action";
	platformsVector = ParseToEnum(platforms);
}