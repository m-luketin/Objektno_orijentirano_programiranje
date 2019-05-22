#include "Game.h"

string Game::Type()
{
	return type;
}

vector<platforms>* Game::Platforms()
{
	return &platformsVector;
}

vector<platforms> Game::ParseToEnum(string str) 
{
	auto cString = const_cast<char*>(str.c_str());
	std::vector<string> arr;
	
	char* current = strtok(cString, ",");
	while (current != NULL) 
	{
		arr.push_back(current);
		current = strtok(NULL, ",");
	}

	vector<platforms> platformsVector;
	while(!arr.empty())
	{
		if(arr.back() == "PC")
			platformsVector.push_back(platforms(0));
		else if(arr.back() == "PS4")
			platformsVector.push_back(platforms(1));
		else if (arr.back() == "XBOX")
			platformsVector.push_back(platforms(2));

			arr.pop_back();
		
	}
	return platformsVector;
}
