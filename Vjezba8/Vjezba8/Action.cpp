#include "Action.h"

using namespace std;

Action::Action(string gameType, vector<enum platforms> gamePlatforms)
{
	type = gameType;
	platforms = gamePlatforms;
}
