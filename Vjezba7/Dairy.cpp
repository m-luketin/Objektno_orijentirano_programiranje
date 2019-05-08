#include "Food.h"
#include "Dairy.h"
#include <string>
#include <iostream>


Dairy::Dairy(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Food( ft, fn, wp, pp, fp, cp, doe, dfr)
{
	mainExpenditure = md;
	sideExpenditure = sd;
}

Dairy::~Dairy()
{
	//delete this;
}

ostream& Dairy::Print(ostream& os) const
{
	Food::Print(os);
	os << "Main dish(kg): " << mainExpenditure << endl
		<< "Side dish(kg): " << sideExpenditure << endl << endl;

	return os;
}

ostream& operator<<(ostream& os, const Dairy& dairy)
{
	return dairy.Print(os);
}