#include "Food.h"
#include <string>
#include <list>
#include <chrono>
#include <iostream>

typedef std::chrono::system_clock Clock;

Food::Food(const std::string foodType, const std::string foodName, const int waterPercentage, const int proteinPercentage, const int fatPercentage, const int carbsPercentage, const std::string dateOfExpiration, const int dailyFoodRequirement)
{
	Type = foodType;
	Name = foodName;
	Water = waterPercentage;
	Protein = proteinPercentage;
	Fat = fatPercentage;
	Carbs = carbsPercentage;
	DateOfExpiration = dateOfExpiration;
	DailyRequirement = dailyFoodRequirement;

	const auto now = Clock::now();
	auto currentClock = Clock::to_time_t(now);
	const auto currentTime = localtime(&currentClock);
	const auto currentMonth = currentTime->tm_mon + 1;
	const auto currentYear = currentTime->tm_year + 1900;

	const auto monthDifference = abs(GetExpirationYear() - currentYear) * 12 + abs(GetExpirationMonth() - currentMonth);

	MonthlySpending = new std::map<std::string, Food>;

	std::cout << "Constructor called!\n";
}

Food::~Food()
{
	//delete[] MonthlySpending;
	//delete this;

	std::cout << "Destructor called!\n";
}

Food::Food(const Food &otherFood)
{
	Type = otherFood.Type;
	Name = otherFood.Name;
	Water = otherFood.Water;
	Protein = otherFood.Protein;
	Fat = otherFood.Fat;
	Carbs = otherFood.Carbs;
	DateOfExpiration = otherFood.DateOfExpiration;
	DailyRequirement = otherFood.DailyRequirement;
	MonthlySpending = otherFood.MonthlySpending;

	std::cout << "Copy-constructor called!\n";
}

void Food::DailyChange(const bool increaseOrDecrease)
{
	if (increaseOrDecrease)
		DailyRequirement++;
	else
		DailyRequirement--;
}

int Food::GetExpirationYear() 
{
	auto year = 0;
	for (auto i = 0; i < 4; i++)
	{
		year += DateOfExpiration[i + 6] - 48;
		year *= 10;
	}

	return year/10;
}

int Food::GetExpirationMonth()
{
	auto month = 0;
	for (auto i = 0; i < 2; i++)
	{
		month += DateOfExpiration[i + 3] - 48;
		month *= 10;
	}

	return month / 10;
}

int Food::GetExpirationDay()
{
	auto day = 0;
	for (auto i = 0; i < 2; i++)
	{
		day += DateOfExpiration[i] - 48;
		day *= 10;
	}
	
	return day / 10;
}


void Food::Print() const
{
	std::cout << Name << "\nType:" << Type
		<< "\nWater pct:" << Water
		<< "\nProtein pct:" << Protein
		<< "\nFat pct:" << Fat
		<< "\nCarbs:" << Carbs
		<< "\nExpiration:" << DateOfExpiration
		<< "\nDaily req:" << DailyRequirement << "\n\n";
}

void Food::EnterMonthlySpending()
{
	

}