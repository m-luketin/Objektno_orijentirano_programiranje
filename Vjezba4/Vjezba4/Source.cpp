#include "Pistol.h"
#include "Target.h"
#include <time.h>
#include <iostream>


bool DidGunHitTarget(Pistol pistol, Target target)
{
	int targetBottom = target.GetPosition().GetHeight();
	int targetTop = target.GetHeight() + targetBottom;
	int pistolHeight = pistol.GetPosition().GetHeight();

	return(targetBottom < pistolHeight && targetTop > pistolHeight);
}


int main()
{
	srand(time(NULL));
	//1st task
	Position firstPosition(2, 9, 20), secondPosition(1, 3, 12);
	std::cout<< "2D points distance:" << firstPosition.Distance(secondPosition, 2) << "\n";
	std::cout << "3D points distance:" << firstPosition.Distance(secondPosition, 3) << "\n";
	
	//4th task
	int n, hitCounter = 0;
	std::cout << "Please enter the number of targets:\n";
	std::cin >> n;

	Target *targets = new Target[n];

	Position gunPosition(0, 0, 0);
	Pistol pistol(gunPosition, 8);

	for (int i = 0; i < n; i++) 
	{
		Target tmpTarget;
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
	
	system("pause");
}