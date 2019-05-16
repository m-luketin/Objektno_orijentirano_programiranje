#pragma once
#include "VideoGame.h"

using namespace std;

class Game : public VideoGame
{
protected:
	vector<platforms> platformsVector;
	string type;

public:
	Game() = default;
	string Type() override;
	vector<platforms> Platforms() override;
};