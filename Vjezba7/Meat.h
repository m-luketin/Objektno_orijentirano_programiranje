#pragma once

#include "Food.h"

class Meat : public Food
{
	float mainExpenditure;
	float sideExpenditure;

public:
	Meat(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Meat();
	friend ostream& operator<<(ostream& os, const Meat& food);
	void Print() override;
};