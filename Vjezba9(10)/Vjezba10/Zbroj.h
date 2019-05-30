#pragma once
#include <iostream>

template <typename T>
class Zbroj
{
	T Prvi;
	T Drugi;
public:
	Zbroj(T prvi, T drugi)
	{
		Prvi = prvi;
		Drugi = drugi;
		std::cout << "Obicni konstruktor!" << std::endl;
	}

	T Zbroji() 
	{
		return Prvi + Drugi;
	}
};

template<>
class Zbroj<char>
{
	char Prvi;
	char Drugi;
public:
	Zbroj(char prvi, char drugi)
	{
		Prvi = prvi;
		Drugi = drugi;
		std::cout << "Char konstruktor!" << std::endl;
	}
	char Zbroji()
	{
		return Prvi + Drugi - 'a' + 1;
	}
};



