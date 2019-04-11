#pragma once
#include <string>
#include <map>

class Food
{
	std::string Type;
	std::string Name;
	int Water;
	int Protein;
	int Fat;
	int Carbs;
	std::string DateOfExpiration;
	int DailyRequirement;
	int* MonthlySpending;

public:
	Food();
	Food(std::string foodType, std::string foodName, int waterPercentage, int proteinPercentage, int fatPercentage, int carbsPercentage, std::string dateOfExpiration, int dailyFoodRequirement);
	~Food();
	Food(const Food &otherFood);
	void DailyChange(bool increaseOrDecrease);
	int GetExpirationYear();
	int GetExpirationMonth();
	int GetExpirationDay();
	void Print();
	void EnterMonthlySpending();
	int AllocationSize();
};
