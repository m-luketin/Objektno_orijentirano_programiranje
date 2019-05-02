#include "Food.h"
#include "Sweets.h"
#include <string>

Sweets::Sweets( const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Food(ft, fn, wp, pp, fp, cp, doe, dfr)
{
	mainExpenditure = md;
}

Sweets::~Sweets()
{
	delete this;
}
