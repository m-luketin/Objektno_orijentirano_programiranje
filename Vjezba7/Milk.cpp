#include "Dairy.h"
#include "Milk.h"
#include <string>

Milk::Milk(const int sd, const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Dairy(sd, md, ft, fn, wp, pp, fp, cp, doe, dfr) {}

Milk::~Milk()
{
	//delete this;
}