#pragma once

#include "VideoGame.h"

class Action : public VideoGame
{
	vector<enum platforms> platforms;
	string type;
public:
	Action(string type, vector<enum platforms> platforms);
	~Action();
};