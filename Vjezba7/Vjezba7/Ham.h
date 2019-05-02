#pragma once

#include "Meat.h"

class Ham : public Meat
{
public:
	Ham(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Ham();
};