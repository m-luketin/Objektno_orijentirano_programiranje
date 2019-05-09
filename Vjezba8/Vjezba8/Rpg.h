#pragma once

#include "VideoGame.h"

class Rpg : public VideoGame
{
	vector<enum platforms> platforms;
	string type;

public:
	Rpg(string type, vector<enum platforms> platforms);
	~Rpg();
};