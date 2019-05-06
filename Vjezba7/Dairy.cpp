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

ostream& operator<<(ostream& os, const Dairy& dairy)
{
	os << (Food)dairy
		<< "Main dish(kg): " << dairy.mainExpenditure << endl
		<< "Side dish(kg): " << dairy.sideExpenditure << endl << endl;
	
	return os;
}

void Dairy::Print()
{
	cout << *this;
}