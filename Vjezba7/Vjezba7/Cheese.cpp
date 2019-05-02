#include "Dairy.h"
#include "Cheese.h"
#include <string>

Cheese::Cheese(const int sd, const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Dairy(sd, md, ft, fn, wp, pp, fp, cp, doe, dfr){}

Cheese::~Cheese()
{
	delete this;
}
