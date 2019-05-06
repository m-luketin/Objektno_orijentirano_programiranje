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

ostream& operator<<(ostream& os, const Meat& meat) 
{
	os << (Food)meat
		<< "Main dish(kg): " << meat.mainExpenditure << endl
		<< "Side dish(kg): " << meat.sideExpenditure << endl << endl;
	return os;
}

void Meat::Print()
{
	cout << *this;
}