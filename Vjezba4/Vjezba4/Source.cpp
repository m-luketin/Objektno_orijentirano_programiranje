#include "Pistol.h"
#include "Target.h"
#include <ctime>
#include <iostream>
#include <random>

bool DidGunHitTarget(Pistol pistol, Target target)
{
	const auto targetBottom = target.GetPosition().GetHeight(),
	targetTop = target.GetHeight() + targetBottom,
	pistolHeight = pistol.GetPosition().GetHeight();

	return(targetBottom < pistolHeight && targetTop > pistolHeight);
}


int main()
{
	srand(time(nullptr));
	//1st task
	Position firstPosition(2, 9, 20);
	const Position secondPosition(1, 3, 12);
	std::cout<< "2D points distance:" << firstPosition.Distance(secondPosition, 2) << "\n";
	std::cout << "3D points distance:" << firstPosition.Distance(secondPosition, 3) << "\n";
	
	//4th task
	int n, hitCounter = 0;
	std::cout << "Please enter the number of targets:\n";
	std::cin >> n;

	auto *targets = new Target[n];

	const Position gunPosition(0, 0, 0);
	const Pistol pistol(gunPosition, 8);

	for (auto i = 0; i < n; i++) 
	{
		const Target tmpTarget;
		targets[i] = tmpTarget;
		std::cout << "Target " << i << ": ";
		targets[i].GetPosition().PrintPosition();
		std::cout << "Height:" << targets[i].GetHeight() << "\n\n";
		if (DidGunHitTarget(pistol, targets[i]))
		{
			targets[i].Hit();
			hitCounter++;
		}
	}

	std::cout << hitCounter << " targets hit!\n";

	delete[] targets;
	system("pause");
}