#pragma once

#include "Dairy.h"

class Milk : public Dairy
{
public:
	Milk(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Milk();
};