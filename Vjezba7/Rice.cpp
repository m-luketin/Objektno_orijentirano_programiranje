#include "Veggie.h"
#include "Rice.h"
#include <string>

Rice::Rice(const int sd, const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Veggie(sd, md, ft, fn, wp, pp, fp, cp, doe, dfr) {}

Rice::~Rice() = default;
