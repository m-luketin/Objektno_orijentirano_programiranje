#pragma once

#include <vector>
#include <string>

using namespace std;

class VideoGame {
public:

	enum platforms {
		PC,
		PS4,
		XBOX
	};

	virtual string Type();
	virtual vector<enum platforms> Platforms();
};

