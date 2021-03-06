#pragma once

#include "Food.h"

class Sweets : public Food
{
	float mainExpenditure;
	float sideExpenditure;

public:
	Sweets(const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Sweets();
	ostream& Print(ostream& os) const override;
};
