#include "Food.h"
#include "Veggie.h"
#include <string>
#include <iostream>

Veggie::Veggie(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Food(ft, fn, wp, pp, fp, cp, doe, dfr)
{
	mainExpenditure = md;
	sideExpenditure = sd;
}

Veggie::~Veggie()
{
	//delete this;
}

ostream& operator<<(ostream& os, const Veggie& veggie)
{
	os << (Food)veggie
		<< "Main dish(kg): " << veggie.mainExpenditure << endl
		<< "Side dish(kg): " << veggie.sideExpenditure << endl << endl;

	return os;
}

void Veggie::Print()
{
	cout << *this;
}
