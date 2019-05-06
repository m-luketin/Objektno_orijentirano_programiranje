#include "Food.h"
#include "Sweets.h"
#include <string>
#include <iostream>

Sweets::Sweets( const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Food(ft, fn, wp, pp, fp, cp, doe, dfr)
{
	mainExpenditure = md;
}

Sweets::~Sweets()
{
	//delete this;
}

ostream& operator<<(ostream& os, const Sweets& sweets)
{
	os << (Food)sweets
		<< "Expenditure(kg): " << sweets.mainExpenditure << endl << endl;

	return os;
}

void Sweets::Print()
{
	cout << *this;
}