#pragma once

#include "Meat.h"

class Prosciutto : public Meat
{
public:
	Prosciutto(const int sd, const int  md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr);
	~Prosciutto();
};