#pragma once

#include "Sweets.h"

class Cake : public Sweets
{
public:
	Cake(const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Cake();
};
