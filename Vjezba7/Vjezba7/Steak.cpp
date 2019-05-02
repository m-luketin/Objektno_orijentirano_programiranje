#include "Meat.h"
#include "Steak.h"
#include <string>

Steak::Steak(const int sd, const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Meat(sd, md, ft, fn, wp, pp, fp, cp, doe, dfr) {}

Steak::~Steak()
{
	delete this;
}
