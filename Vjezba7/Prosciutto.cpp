#include "Meat.h"
#include "Prosciutto.h"
#include <string>

Prosciutto::Prosciutto(const int sd, const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Meat(sd, md, ft, fn, wp, pp, fp, cp, doe, dfr) {}

Prosciutto::~Prosciutto() = default;
