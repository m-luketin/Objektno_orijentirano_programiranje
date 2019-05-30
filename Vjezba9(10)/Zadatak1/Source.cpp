#include "Stack.h"

int main()
{
	Stack<int> myStack(1, 1);

	myStack.Push(5);
	myStack.Push(10);
	myStack.Push(15);
	myStack.Push(20);

	std::cout << myStack.Pop() << std::endl;
	std::cout << myStack.Pop() << std::endl;
	std::cout << myStack.Pop() << std::endl;
	std::cout << myStack.Pop() << std::endl;

	system("pause");
}