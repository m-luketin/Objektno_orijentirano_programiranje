#include "Dairy.h"
#include "Yoghurt.h"
#include <string>

Yoghurt::Yoghurt(const int sd, const int md, const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
	: Dairy(sd, md, ft, fn, wp, pp, fp, cp, doe, dfr) {}

Yoghurt::~Yoghurt()
{
	delete this;
}