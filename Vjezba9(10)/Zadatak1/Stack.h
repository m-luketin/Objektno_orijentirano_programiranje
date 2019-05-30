#pragma once
#include <iostream>

template<typename T>
class Stack
{
	const int defaultSize = 10;
	const int maxSize = 1000;
	int size;
	T top;
	T* stackPointer;

public:
	Stack(T elementToPush)
	{
		stackPointer = new T[maxSize];

		for (auto i = 0; i < defaultSize; i++)
		{
			Push(elementToPush);
		}
	}

	Stack(T elementToPush, int sizeToAssign)
	{
		stackPointer = new T[maxSize];
		for (auto i = 0; i < sizeToAssign; i++)
		{
			Push(elementToPush);
		}
	}

	~Stack()
	{
		while(size)
		{
			--stackPointer;
			--size;
		}
		delete[] stackPointer;
	}

	void Push(T elementToPush)
	{
		if (!IsFull())
		{
			*stackPointer = elementToPush;
			top = *stackPointer;
			++stackPointer;
			++size;
		}
		else
			std::cout << "Stack is full, sorry!" << std::endl;
	}

	bool IsFull() const
	{
		return(size == maxSize);
	}

	bool IsEmpty() const
	{
		return(size == 0);
	}

	T Pop()
	{
		if (!IsEmpty())
		{
			auto result = top;
			--stackPointer;
			--size;
			top = *(stackPointer - 1);
			return result;
		}

		std::cout << "Stack is empty, sorry!" << std::endl;
	}

	int GetSize()
	{
		return size;
	}

	template<typename T>T GetTop()
	{
		return top;
	}
};

