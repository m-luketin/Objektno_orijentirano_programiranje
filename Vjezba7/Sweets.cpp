#include "Food.h"
#include "Sweets.h"
#include <string>
#include <iostream>

Sweets::Sweets( const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Food(ft, fn, wp, pp, fp, cp, doe, dfr)
{
	mainExpenditure = md;
}

Sweets::~Sweets() = default;

ostream& Sweets::Print(ostream& os) const
{
	Food::Print(os);
	os << "Main dish(kg): " << mainExpenditure << endl << endl;

	return os;
}

