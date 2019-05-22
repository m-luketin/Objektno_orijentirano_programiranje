#pragma once
#include "Game.h"


class Counter
{
	int pcGames;
	int ps4Games;
	int xboxGames;

public:
	Counter();
	void TypeOfGame(Game game);
	void IncrementPc();
	void IncrementPs4();
	void IncrementXbox();
	void PrintMax() const;
};
