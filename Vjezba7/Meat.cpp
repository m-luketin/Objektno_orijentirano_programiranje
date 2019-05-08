#include "Food.h"
#include "Meat.h"
#include <string>
#include <iostream>

Meat::Meat(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Food(ft, fn, wp, pp, fp, cp, doe, dfr)
{
	mainExpenditure = md;
	sideExpenditure = sd;
}

Meat::~Meat()
{
	//delete this;
}

ostream& Meat::Print(ostream& os) const
{
	Food::Print(os);
	os << "Main dish(kg): " << mainExpenditure << endl
		<< "Side dish(kg): " << sideExpenditure << endl << endl;

	return os;
}

ostream& operator<<(ostream& os, const Meat& meat)
{
	return meat.Print(os);
}