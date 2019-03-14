#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int numberArray[] = { 1, 4, 7, 3, 8, 2, 9, 2, 9, 7 };
	int N = sizeof(numberArray) / sizeof(int);

	for (int i = 0; i < 10; i++) {
		int counter = 0;
		for (int j = 0; j < N; j++) {
			if (numberArray[j] == i)
				counter++;
		}
		if(counter)
			cout << i << " - " << counter << " puta" << endl;
	}
	system("pause");
}