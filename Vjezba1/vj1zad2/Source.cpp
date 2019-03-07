#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct student
{
	char id[3];
	char name[30];
	bool gender;
	int quiz_grades[2];
	int mid_term_grade;
	int final_grade;
	int total_grade;
};

bool is_full(student *students, int n) {
	for (int i = 0; i < n; i++) {
		if (!strcmp("\0", students[i].id))
			return false;
	}
	return true;
}

bool is_empty(student* students, int n) {
	for (int i = 0; i < n; i++) {
		if (students[i].id != NULL)
			return false;
	}
	return true;
}

bool id_in_array(student* students, char* id, int n){
	for (int i = 0; i < n; i++) {
		if (students[i].id == id)
			return true;
	}
	return false;
}

void add_student(student **students, int n) {
	if (!is_full(*students, n)) { //checking if list is full
		for (int i = 0; i < n; i++) {
			if (!strcmp((*students)[i].id, "\0")) {
				cout << "Enter student ID";
				char id[3];
				cin >> id;
				if (id_in_array(*students, id, n)) //checking if id is already in array
				{
					cout << "Id already belongs to a student!";
					break;
				}
				else
				{
					(*(*students)[i].id) = *id;
					cout << "Enter student's name";
					cin >> (*students)[i].name;
					cout << "Enter 1 for male, 0 for female";
					cin >> (*students)[i].gender;
					cout << "Enter the first quiz grade";
					cin >> (*students)[i].quiz_grades[0];
					cout << "Enter the second quiz grade";
					cin >> (*students)[i].quiz_grades[1];
					cout << "Enter the mid term grade";
					cin >> (*students)[i].quiz_grades[0];
					cout << "Enter the final grade";
					cin >> (*students)[i].quiz_grades[0];
				}
			}
		}
	}
	else
		cout << "Max number of students already in class!";
}

int main() {
	student *array_of_students; 
	int max_students = 30;
	array_of_students = (student*)calloc(max_students, sizeof(student));

	array_of_students[0] = { "1", "Alex Amanzi", 1, (4, 5), 4, 5, NULL };
	array_of_students[1] = { "2", "Marko Juric", 1, (2, 2), 2, 2, NULL };
	array_of_students[2] = { "3", "Ivan Peric", 1, (2, 5), 2, 5, NULL };
	array_of_students[3] = { "4", "Ante Vuletic", 1, (3, 3), 3, 3, NULL };
	array_of_students[4] = { "5", "Ivana Antic", 0, (2, 4), 3, 5, NULL };
	array_of_students[5] = { "6", "Jure Radun", 1, (1, 5), 2, 3, NULL };
	array_of_students[6] = { "7", "Sime Simunic", 1, (3, 2), 2, 3, NULL };
	array_of_students[7] = { "8", "Marin Kovac", 1, (1, 1), 1, 1, NULL };
	array_of_students[8] = { "9", "Antonia Juric", 0, (2, 3), 3, 4, NULL };
	array_of_students[9] = { "10", "Marina Veljic", 0, (4, 4), 4, 4, NULL };
	array_of_students[10] = { "11", "Petar Baric", 1, (2, 2), 2, 2, NULL };
	array_of_students[11] = { "12", "Lora Zderic", 0, (3, 2), 3, 2, NULL };
	array_of_students[12] = { "13", "Ivo Strmotic", 1, (4, 5), 4, 5, NULL };
	array_of_students[13] = { "14", "Mateo Ivic", 1, (5, 2), 4, 3, NULL };
	array_of_students[14] = { "15", "Antonio Katic", 1, (2, 1), 2, 2, NULL };
	array_of_students[15] = { "16", "Mario Krolo", 1, (3, 4), 2, 4, NULL };
	array_of_students[16] = { "17", "Tea Begonja", 0, (2, 5), 3, 3, NULL };
	array_of_students[17] = { "18", "Ivica Lulic", 1, (1, 5), 2, 5, NULL };
	array_of_students[18] = { "19", "Toma Maric", 1, (4, 5), 4, 5, NULL };
	array_of_students[19] = { "20", "Matija Luketin", 1, (5, 5), 5, 5, NULL };



	int selection = 1;
	while (selection != 0) {
		cout << "Choose action:\n(1)Add student\n(2)Remove student\n(3)Update student\n(4)View students\n(5)Calculate student's total\n";
		cout << "(6)Best student\n(7)Worst student\n(8)Search by ID\n(9)Sort by total\n(0)Quit\n";
		cin >> selection;

		switch(selection) {
			case 1:
				add_student(&array_of_students, max_students);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
		}
	}
	
	return 0;
	system("pause");
}