#include "Food.h"
#include <string>
#include <list>
#include <chrono>
#include <iostream>
#include <array>
#include <algorithm>
#include <cctype>

typedef std::chrono::system_clock Clock;

Spending::Spending()
{
	year = 0;
	month = 0;
	spending = 0;
}

Food::Food(const std::string ft, const std::string fn, const int wp, const int pp, const int fp, const int cp, const std::string doe, const int dfr)
{
	Type = ft;
	Name = fn;
	Water = wp;
	Protein = pp;
	Fat = fp;
	Carbs = cp;
	DateOfExpiration = doe;
	DailyRequirement = dfr;

	MonthlySpending = new Spending[AllocationSize()];

	std::cout << "Constructor called!\n";
}

Food::~Food()
{
	delete[] MonthlySpending;
	delete this;

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

	MonthlySpending = new Spending[AllocationSize()];

	for ( auto i = 0; i < AllocationSize(); i++)
		MonthlySpending[i] = otherFood.MonthlySpending[i];

	std::cout << "Copy-constructor called!\n";
}

int Food::AllocationSize()
{
	const auto now = Clock::now();
	auto currentClock = Clock::to_time_t(now);
	const auto currentTime = localtime(&currentClock);
	const auto currentMonth = currentTime->tm_mon + 1;
	const auto currentYear = currentTime->tm_year + 1900;

	const auto monthDifference = abs(GetExpirationYear() - currentYear) * 12 + abs(GetExpirationMonth() - currentMonth);

	return monthDifference;
}

void Food::DailyChange(const int increaseOrDecrease)
{
	if (increaseOrDecrease == 1)
		DailyRequirement++;
	else if(increaseOrDecrease == -1)
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


void Food::Print()
{
	std::cout << Name << "\nType:" << Type
		<< "\nWater pct:" << Water
		<< "\nProtein pct:" << Protein
		<< "\nFat pct:" << Fat
		<< "\nCarbs:" << Carbs
		<< "\nExpiration:" << DateOfExpiration
		<< "\nDaily req:" << DailyRequirement << "\nMonthly spending: ";

	for (auto i = 0; i < AllocationSize(); i++)
	{
		if(MonthlySpending[i].year)
			std::cout << MonthlySpending[i].month << " " << MonthlySpending[i].year << " " << MonthlySpending[i].spending << "   ";
	}
	std::cout << "\n\n";
}

int CompareIntegers(const int a, const int b) {
	if (a < b) {
		return -1;
	}
	else if (a > b) {
		return 1;
	}
	return 0;
}

int Compare(const void *a, const void *b) {
	const Spending *firstElement = (Spending *)a;
	const Spending *secondElement = (Spending *)b;

	if (firstElement->year == secondElement->year) {
		return CompareIntegers(firstElement->month, secondElement->month);
	}
	else if (firstElement->year > secondElement->year) {
		return +1;
	}
	return -1;
}

void Food::RandomizeMonthlySpending()
{
	for (auto i = 0; i < AllocationSize(); i++)
	{
		MonthlySpending[i].year = int(rand() % 3 + 2017);
		MonthlySpending[i].month = int(rand() % 12 + 1);
		MonthlySpending[i].spending = int(rand() % 50);
	}
	qsort(MonthlySpending, AllocationSize(), sizeof(Spending), Compare);
}

void Food::EnterMonthlySpending()
{
	const auto now = Clock::now();
	auto currentClock = Clock::to_time_t(now);
	const auto currentTime = localtime(&currentClock);
	const auto currentYear = currentTime->tm_year + 1900;

	char tmpMonth;
	std::cout << "Enter month number for spending:\n";
	std::cin >> tmpMonth;
	if (!std::isdigit(tmpMonth))
	{
		std::cout << "Not a number!\n";
		return;
	}
	else if ((tmpMonth - 48) < 0 || (tmpMonth - 48) > 12)
	{
		std::cout << "Not a valid month!\n";
		return;
	}

	std::string tmpSpending;
	std::cout << "Enter spending:\n";
	std::cin >> tmpSpending;
	const auto tmpSpendingNum = std::stoi(tmpSpending);

	if ((tmpSpendingNum - 48) < 0)
	{
		std::cout << "Not a valid entry!\n";
		return;
	}

	for (auto i = 0; i < AllocationSize(); i++)
	{
		if(MonthlySpending[i].year == currentYear ||
			MonthlySpending[i].month == tmpMonth - 48 ||
			MonthlySpending[i].spending == tmpSpendingNum)
		{
			std::cout << "Month already entered!\n";
			return;
		}
	}

	for (auto i = 0; i < AllocationSize(); i++)
	{
		if (!MonthlySpending[i].year) {
			MonthlySpending[i].year = currentYear;
			MonthlySpending[i].month = tmpMonth - 48;
			MonthlySpending[i].spending = tmpSpendingNum;

			qsort(MonthlySpending, AllocationSize(), sizeof(Spending), Compare);
			return;
		}
	}
	std::cout << "No more space for entries!\n";
}

int Food::CalculateSpendingChange()
{
	const auto now = Clock::now();
	auto currentClock = Clock::to_time_t(now);
	const auto currentTime = localtime(&currentClock);
	const auto currentYear = currentTime->tm_year + 1900;

	auto lastYearSum = 0, thisYearSum = 0, lastYearCount = 0, thisYearCount = 0;

	for (auto i = 0; i < AllocationSize(); i++)
	{
		if (MonthlySpending[i].year == currentYear - 1)
		{
			lastYearSum += MonthlySpending[i].spending;
			lastYearCount++;
		}
	}
	const auto lastYearAverage = double(lastYearSum) / lastYearCount;

	for (auto i = 0; i < AllocationSize(); i++)
	{
		if (MonthlySpending[i].year == currentYear)
		{
			thisYearSum += MonthlySpending[i].spending;
			thisYearCount++;
		}
	}
	const auto thisYearAverage = double(thisYearSum) / thisYearCount;

	if (thisYearAverage / lastYearAverage > 1.1)
		return 1;
	if (thisYearAverage / lastYearAverage < 0.9)
		return -1;

	return 0;
}
