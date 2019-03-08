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


student* seed_students(int max_students) {
	student* array_of_students;
	array_of_students = (student*)calloc(max_students, sizeof(student));

	array_of_students[0] = { "1", "Alex Amanzi", 1, (4, 5), 4, 5, 18 };
	array_of_students[1] = { "2", "Marko Juric", 1, (2, 2), 2, 2, NULL };
	array_of_students[2] = { "3", "Ivan Peric", 1, (2, 5), 2, 5, 14 };
	array_of_students[3] = { "4", "Ante Vuletic", 1, (3, 3), 3, 3, 12 };
	array_of_students[4] = { "5", "Ivana Antic", 0, (2, 4), 3, 5, NULL };
	array_of_students[5] = { "6", "Jure Radun", 1, (1, 5), 2, 3, NULL };
	array_of_students[6] = { "7", "Sime Simunic", 1, (3, 2), 2, 3, NULL };
	array_of_students[7] = { "8", "Marin Kovac", 1, (1, 1), 1, 1, NULL };
	array_of_students[8] = { "9", "Antonia Juric", 0, (2, 3), 3, 4, 12 };
	array_of_students[9] = { "10", "Marina Veljic", 0, (4, 4), 4, 4, NULL };
	array_of_students[10] = { "11", "Petar Baric", 1, (2, 2), 2, 2, 8 };
	array_of_students[11] = { "12", "Lora Zderic", 0, (3, 2), 3, 2, NULL };
	array_of_students[12] = { "13", "Ivo Strmotic", 1, (4, 5), 4, 5, NULL };
	array_of_students[13] = { "14", "Mateo Ivic", 1, (5, 2), 4, 3, 14 };
	array_of_students[14] = { "15", "Antonio Katic", 1, (2, 1), 2, 2, NULL };
	array_of_students[15] = { "16", "Mario Krolo", 1, (3, 4), 2, 4, 13 };
	array_of_students[16] = { "17", "Tea Begonja", 0, (2, 5), 3, 3, 13 };
	array_of_students[17] = { "18", "Ivica Lulic", 1, (1, 5), 2, 5, NULL };
	array_of_students[18] = { "19", "Toma Maric", 1, (4, 5), 4, 5, NULL };
	array_of_students[19] = { "20", "Matija Luketin", 1, (5, 5), 5, 5, 20 };

	return array_of_students;
}

void print_menu() {
	cout << "Choose action:\n(1)Add student\n(2)Remove student\n(3)Update student\n(4)View students\n(5)Calculate student's total\n";
	cout << "(6)Best student\n(7)Worst student\n(8)Search by ID\n(9)Sort by total\n(0)Quit\n";
}

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

bool is_full(student *students, int n) {
	for (int i = 0; i < n; i++) {
		if (!strcmp("\0", students[i].id))
			return false;
	}
	return true;
}

bool is_completely_empty(student* students, int n) {
	for (int i = 0; i < n; i++) {
		if (strcmp("\0", students[i].id))
			return false;
	}
	return true;
}// is_empty ambiguity error?

bool id_in_array(student* students, char* id, int n){
	for (int i = 0; i < n; i++) {
		if (!strcmp(students[i].id, id))
			return true;
	}
	return false;
}

int index_by_id(student* students, char* id, int n) {
	for (int i = 0; i < n; i++) {
		if (!strcmp(students[i].id, id))
			return i;
	}
	return -1;
}

void add_student(student **students, int n) {
	if (is_full(*students, n)) { //checking if list is full
		cout << "Max number of students already in class!\n\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (strcmp(students[i]->id, "\0")) {//if array[i] contains a student, skip for loop iteration 
			continue;
		}

		cout << "Enter student ID\n";
		char id[3];
		cin >> id;

		if (id_in_array(*students, id, n)) //checking if id is already in array
		{
			cout << "Id already belongs to a student!\n\n";
		}
		else
		{
			strcat(students[i]->id, id);
			cout << "Enter student's full name\n";
			cin >> students[i]->name;
			cout << "Enter 1 for male, 0 for female\n";
			cin >> students[i]->gender;
			cout << "Enter the first quiz grade\n";
			cin >> students[i]->quiz_grades[0];
			cout << "Enter the second quiz grade\n";
			cin >> students[i]->quiz_grades[1];
			cout << "Enter the mid term grade\n";
			cin >> students[i]->quiz_grades[0];
			cout << "Enter the final grade\n";
			cin >> students[i]->quiz_grades[0];
		}
	}
}

void remove_student(student **students, int n, char id = '\0') { // 2 arguments-remove prompt, 3 arguments-remove by id
	
	if (is_completely_empty(*students, n)) { //checking if array is empty
		cout << "There are no students to delete!\n\n";
	}
	else {
		if (!id) {
			cout << "Enter student ID\n";
			cin >> id;
		}
		if (!id_in_array(*students,(char*)id, n)) //checking if id is taken
		{
			cout << "Id not found!\n\n";
		}
		else
		{
			int index = index_by_id(*students, (char*)id, n); //getting index of the student to delete

			if (index != -1) { //checking that index_by_id didnt fail
				strcpy(students[index]->name, "\0");
				strcpy(students[index]->id, "\0");
				students[index]->gender = NULL;
				students[index]->quiz_grades[0] = NULL;
				students[index]->quiz_grades[1] = NULL;
				students[index]->mid_term_grade = NULL;
				students[index]->final_grade = NULL;
				students[index]->total_grade = NULL;
				cout << "Student removed!\n\n";
			}
			else
				cout << "Error finding index!";
		}
	}
}

void update_student(student **students, int n) {
	cout << "Enter student ID\n";
	char id[3];
	cin >> id;

	if (!id_in_array(*students, id, n)) //checking if id is already in array 
	{
		cout << "Id not found!\n\n";
	}
	else
	{
		int index = index_by_id(*students, id, n); //getting index of the student to update

		if (index != -1) { //checking that index_by_id didnt fail
			cout << "Enter student's full name\n";
			cin >> students[index]->name;
			cout << "Enter 1 for male, 0 for female\n";
			cin >> students[index]->gender;
			cout << "Enter the first quiz grade\n";
			cin >> students[index]->quiz_grades[0];
			cout << "Enter the second quiz grade\n";
			cin >> students[index]->quiz_grades[1];
			cout << "Enter the mid term grade\n";
			cin >> students[index]->quiz_grades[0];
			cout << "Enter the final grade\n";
			cin >> students[index]->quiz_grades[0];
			cout << "Student updated!\n\n";
		}
		else
			cout << "Error finding index!";
	}
}

void print_students(student *students, int high, int low = 0) { //implemented with lower limit (default = 0) for reusability
	if (is_completely_empty(students, high)) {
		return;
	}
	for (; low < high; low++)
	{
		if(strcmp(students[low].id, "\0")){
			cout << "------------------------------------\n";
			cout << "Student:  " << students[low].id << "  " << students[low].name;
			students[low].gender ? cout << "  Male" : cout << "  Female"; //converting bool to string
			cout << "\nGrades:     " << students[low].quiz_grades[0] << "     " << students[low].quiz_grades[1] << "     " << students[low].mid_term_grade << "\n";
			if (students[low].total_grade == NULL)// != changed for testing
				cout << "Total grade:   " << students[low].total_grade << "\n";
			cout << "------------------------------------\n";

		}
	}
}

void calculate_total_grade(student **students, int n) {
	cout << "Enter student ID\n";
	char id[3];
	cin >> id;

	if (!id_in_array(*students, id, n)) //checking if id is already in array 
	{
		cout << "Id not found!\n\n";
	}
	else
	{
		int index = index_by_id(*students, id, n); //getting index of the student to update

		if (index != -1) //checking that index_by_id didnt fail
			students[index]->total_grade = students[index]->quiz_grades[1] + students[index]->quiz_grades[0] + students[index]->mid_term_grade + students[index]->final_grade;
		else
			cout << "Error finding index!";
	}
}

void print_best_student(student *students, int n) {
	int best_student_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].total_grade > students[best_student_index].total_grade) 
			best_student_index = i;
	}
	print_students(students, best_student_index + 1, best_student_index);
}

void print_worst_student(student *students, int n) {
	int worst_student_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].total_grade > students[worst_student_index].total_grade)
			worst_student_index = i;
	}
	print_students(students, worst_student_index + 1, worst_student_index);
}

void print_student_by_id(student *students, int n) {
	cout << "Enter student ID\n";
	char id[3];
	cin >> id;
	int index = index_by_id(students, id, n);
	print_students(students, index + 1, index);
}

void bubblesort_students_by_total(student **students, int n) {
	if (is_completely_empty(*students, n)) {
		return;
	}

	bool still_sorting = true;
	while (still_sorting) {
		still_sorting = false;
		for (int j = 0; j < n - 1; j++)
		{
			if (strcmp(students[j]->id, "\0") || strcmp(students[j + 1]->id, "\0")) //execute unless both are null
			{
				if (!strcmp(students[j]->id, "\0")) {//if the first one is null, swap
					students[j] = students[j + 1];
					remove_student(students, n, j + 1); //remove by id
					still_sorting = true;
				}
				else if (students[j]->total_grade > students[j+1]->total_grade) //if not in ascending order, swap
				{
					student *temp;
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
					still_sorting = true;
				}
			}
		}
	}
	print_students(*students, n);
} //build succeeded, crashes program

int main() {
	 
	int max_students = 30;
	student *array_of_students = seed_students(max_students);

	int selection = 1;
	while (selection != 0) {
		print_menu();
		cin >> selection;

		switch(selection) { // maybe put this in a function
			case 1:
				add_student(&array_of_students, max_students);
				break;
			case 2:
				remove_student(&array_of_students, max_students);
				break;
			case 3:
				update_student(&array_of_students, max_students);
				break;
			case 4:
				print_students(array_of_students, max_students);// does not print the proper total grade
				break;
			case 5:
				calculate_total_grade(&array_of_students, max_students);
				break;
			case 6:
				print_best_student(array_of_students, max_students);
				break;
			case 7:
				print_worst_student(array_of_students, max_students);
				break;
			case 8:
				print_student_by_id(array_of_students, max_students);
				break;
			case 9:
				bubblesort_students_by_total(&array_of_students, max_students); // not in function
				break;
		}
	}
	
	return 0;
	system("pause");
}