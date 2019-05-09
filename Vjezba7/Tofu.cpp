#include "Veggie.h"
#include "Tofu.h"
#include <string>

Tofu::Tofu(const int sd, const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Veggie(sd, md, ft, fn, wp, pp, fp, cp, doe, dfr) {}

Tofu::~Tofu() = default;
