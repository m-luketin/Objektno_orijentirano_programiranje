#pragma once

#include "Rpg.h"

class DarkSouls : public Rpg
{
	vector<enum platforms> platforms;
	string type;

public:
	Rpg(string type, vector<enum platforms> platforms);
	~Rpg();
};