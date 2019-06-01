#include "Header.h"

int main()
{
	char firstOperand = 'a', operatorChar, secondOperand = 'a';

	std::cout << PreformOperation('5', '+', '7') << std::endl;

	while (!(firstOperand == '0' && secondOperand == '0'))
	{
		std::cout << "Enter two single digit numbers with an operator between them:" << std::endl;
		std::cin >> firstOperand;
		std::cin >> operatorChar;
		std::cin >> secondOperand;
		std::cout << PreformOperation(firstOperand, operatorChar, secondOperand) << std::endl;
	}

	system("pause");
}