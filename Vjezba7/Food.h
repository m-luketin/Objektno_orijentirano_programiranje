#pragma once
#include <string>
#include <map>

using namespace std;

class Spending
{
public:
	int year;
	int month;
	int spending;

	Spending();
};

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
	Spending* MonthlySpending;

public:
	Food(std::string foodType, std::string foodName, int waterPercentage, int proteinPercentage, int fatPercentage, int carbsPercentage, std::string dateOfExpiration, int dailyFoodRequirement);
	~Food();
	Food(const Food &otherFood);
	void DailyChange(int increaseOrDecrease);
	int GetExpirationYear() const;
	int GetExpirationMonth() const;
	int GetExpirationDay() const;
	void EnterMonthlySpending();
	void RandomizeMonthlySpending();
	int AllocationSize() const;
	int CalculateSpendingChange();
	virtual ostream& Print(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Food& food);
};
