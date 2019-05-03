#include "Sweets.h"
#include "Madjarica.h"
#include <string>

Madjarica::Madjarica(const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Sweets(md, ft, fn, wp, pp, fp, cp, doe, dfr) {}

Madjarica::~Madjarica()
{
	delete this;
}
