#pragma once

#include <vector>
#include <string>
#include "PlatformsEnum.cpp"

using namespace std;

class VideoGame {
public:

	virtual string Type() = 0;
	virtual vector<platforms>* Platforms() = 0;
};

