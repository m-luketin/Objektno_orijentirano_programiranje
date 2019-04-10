#include "Food.h"
#include <string>
#include <list>
#include <chrono>
#include <iostream>

Food::Food(char* foodType, char* foodName, int waterPercentage, int proteinPercentage, int fatPercentage, int carbsPercentage, char* dateOfExpiration, int dailyFoodRequirement)
{
	type = foodType;
	name = foodName;
	water = waterPercentage;
	protein = proteinPercentage;
	fat = fatPercentage;
	carbs = carbsPercentage;
	date = dateOfExpiration;
	dailyRequirement = dailyFoodRequirement;

	std::string parsedDate = date.split("-");
	
	monthlySpending = new int[];
}

Food::~Food()
{
	delete[] monthlySpending;
	delete this;
}

Food::Food(const Food &otherFood)
{
	type = otherFood.type;
	name = otherFood.name;
	water = otherFood.water;
	protein = otherFood.protein;
	fat = otherFood.fat;
	carbs = otherFood.carbs;
	date = otherFood.date;
	dailyRequirement = otherFood.dailyRequirement;
	monthlySpending = otherFood.monthlySpending;
}

void Food::DailyChange(bool increaseOrDecrease)
{
	if (increaseOrDecrease)
		dailyRequirement++;
	else
		dailyRequirement--;
}

int Food::GetExpirationYear() 
{
	int year;
	for (int i = 0; i < 4; i++)
	{
		year += date[i + 6] - 48;
		year *= 10;
	}

	return year/10;
}

int Food::GetExpirationMonth()
{
	int month;
	for (int i = 0; i < 2; i++)
	{
		month += date[i + 3] - 48;
		month *= 10;
	}

	return month / 10;
}

int Food::GetExpirationDay()
{
	int day;
	for (int i = 0; i < 2; i++)
	{
		day += date[i] - 48;
		day *= 10;
	}

	return day / 10;
}

int Food::CalculateAllocationSize()
{
	tm* time = localtime(NULL);
	std::cout << time;

}