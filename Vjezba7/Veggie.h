#pragma once

#include "Food.h"

class Veggie : public Food
{
	float mainExpenditure;
	float sideExpenditure;

public:
	Veggie(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Veggie();
	ostream& Print(ostream& os) const override;
};