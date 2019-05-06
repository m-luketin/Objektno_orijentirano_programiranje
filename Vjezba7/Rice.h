#pragma once

#include "Veggie.h"

class Rice : public Veggie
{
public:
	Rice(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Rice();
};
