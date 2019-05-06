#pragma once

#include "Food.h"

class Dairy : public Food
{
protected:
	float mainExpenditure;
	float sideExpenditure;

public:
	Dairy(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Dairy();
	friend ostream& operator<<(ostream& os, const Dairy& dairy);
	void Print() override;
};