#pragma once

#include "Meat.h"

class Steak : public Meat
{
public:
	Steak(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Steak();
};