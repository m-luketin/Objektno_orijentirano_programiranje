#pragma once
#include <cctype>
#include <exception>
#include <string>
#include <iostream>
#include <fstream>

class MyException : std::exception
{
	std::string errorMessage;

public:
	MyException(std::string myErrorMessage)
	{
		errorMessage = myErrorMessage;
		std::cout << errorMessage << std::endl;
		WriteToLog();
	};

	void WriteToLog()
	{
		std::ofstream fout("errors.log", std::ios_base::out | std::ios_base::app);
		fout << errorMessage;
		fout << '\n';
	}

};

bool IsOperandValid(char input)
{
	try
	{
		if(!isdigit(input))
			throw MyException("Digits only!");
	}
	catch (MyException e)
	{
		std::cout << "Caught the exception!" << std::endl;
		return false;
	}
	
	
	return true;
}

bool IsOperatorvalid(char input)
{
	char validOperators[4] = { '+', '-', '*', '/' };

	try
	{
		if (!std::strchr(validOperators, input))
			throw MyException("Operator not valid!");
	}
	catch (MyException e)
	{
		std::cout << "Caught the exception!" << std::endl;
		return false;
	}

	return true;
}

int PreformOperation(char firstOperand, char operatorChar, char secondOperand)
{
	if(!IsOperandValid(firstOperand) || !IsOperandValid(secondOperand) || !IsOperatorvalid(operatorChar))
		return 0;

	try
	{
		if (secondOperand == '0' && operatorChar == '/')
			throw MyException("Cant divide by zero, sorry!");
			
		if (operatorChar == '+')
			return((firstOperand - 48) + (secondOperand - 48));
		if (operatorChar == '-')
			return((firstOperand - 48) - (secondOperand - 48));
		if (operatorChar == '/')
			return((firstOperand - 48) / (secondOperand - 48));
		if (operatorChar == '*')
			return((firstOperand - 48) * (secondOperand - 48));
	}
	catch (MyException e)
	{
		std::cout << "Caught the exception!" << std::endl;
		return firstOperand;
	}
}

