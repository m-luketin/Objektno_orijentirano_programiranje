#pragma once

#include "VideoGame.h"

class OpenWorld : public VideoGame
{
	vector<enum platforms> platforms;
	string type;
public:
	OpenWorld(string type, vector<enum platforms> platforms);
	~OpenWorld();
};