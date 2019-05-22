#include "Counter.h"
#include <iostream>

Counter::Counter()
{
	pcGames = 0;
	ps4Games = 0;
	xboxGames = 0;
}

void Counter::TypeOfGame(Game game)
{
	for(auto i = (*game.Platforms()).begin(); i != (*game.Platforms()).end(); ++i)
	{
		if (*i == PC)
			IncrementPc();
		else if (*i == PS4)
			IncrementPs4();
		else if (*i == XBOX)
			IncrementXbox();
	}
}

void Counter::IncrementPc()
{
	pcGames++;
}

void Counter::IncrementPs4()
{
	ps4Games++;
}

void Counter::IncrementXbox()
{
	xboxGames++;
}

void Counter::PrintMax() const
{
	if (pcGames >= xboxGames && pcGames >= ps4Games)
		std::cout << "PC" << endl;
	if (ps4Games >= xboxGames && ps4Games >= pcGames)
		std::cout << "PS4" << endl;
	else
		std::cout << "XBOX" << endl;
}
