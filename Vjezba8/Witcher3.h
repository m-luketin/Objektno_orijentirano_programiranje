#pragma once

#include "Rpg.h"
#include "OpenWorld.h"

class Witcher3 : virtual public Rpg, virtual public OpenWorld
{
	vector<platforms> platformsVector;
	string type;

public:
	Witcher3();
	string Type() override;
	vector<platforms> Platforms() override;
};