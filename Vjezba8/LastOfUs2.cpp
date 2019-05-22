#include "LastOfUs2.h"

LastOfUs2::LastOfUs2(string platforms)
{
	type = "Action";
	platformsVector = ParseToEnum(platforms);
}