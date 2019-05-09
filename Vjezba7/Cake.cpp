#include "Sweets.h"
#include "Cake.h"
#include <string>
#include <iostream>
Cake::Cake(const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Sweets(md, ft, fn, wp, pp, fp, cp, doe, dfr) {}

Cake::~Cake() = default;
