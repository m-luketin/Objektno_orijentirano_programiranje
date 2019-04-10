#pragma once

class Food
{
	std::string type;
	std::string name;
	int water;
	int protein;
	int fat;
	int carbs;
	std::string date;
	int dailyRequirement;
	int* monthlySpending;

public:
	Food(char* foodType, char* foodName, int waterPercentage, int proteinPercentage, int fatPercentage, int carbsPercentage, char* dateOfExpiration, int dailyFoodRequirement);
	~Food();
	Food(const Food &otherFood);
	void DailyChange(bool increaseOrDecrease);
	int GetExpirationYear();
	int GetExpirationMonth();
	int GetExpirationDay();
	int CalculateAllocationSize();
};