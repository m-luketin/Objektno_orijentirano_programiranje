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

student* seed_students(int max_students) 
{
	student* array_of_students;
	array_of_students = (student*)calloc(max_students, sizeof(student));

	array_of_students[0] = { "1", "Alex Amanzi", 1, {4, 5 }, 4, 5, 18};
	array_of_students[1] = { "2", "Marko Juric", 1, {2, 2}, 2, 2, NULL };
	array_of_students[2] = { "3", "Ivan Peric", 1, {2, 5}, 2, 5, 14 };
	array_of_students[3] = { "4", "Ante Vuletic", 1, {3, 3}, 3, 3, 12 };
	array_of_students[4] = { "5", "Ivana Antic", 0, {2, 4}, 3, 5, NULL };
	array_of_students[5] = { "6", "Jure Radun", 1, {1, 5}, 2, 3, NULL };
	array_of_students[6] = { "7", "Sime Simunic", 1, {3, 2}, 2, 3, NULL };
	array_of_students[7] = { "8", "Marin Kovac", 1, {1, 1}, 1, 1, NULL };
	array_of_students[8] = { "9", "Antonia Juric", 0, {2, 3}, 3, 4, 12 };
	array_of_students[9] = { "10", "Marina Veljic", 0, {4, 4}, 4, 4, NULL };
	array_of_students[10] = { "11", "Petar Baric", 1, {2, 2}, 2, 2, 8 };
	array_of_students[11] = { "12", "Lora Zderic", 0, {3, 2}, 3, 2, NULL };
	array_of_students[12] = { "13", "Ivo Strmotic", 1, {4, 5}, 4, 5, NULL };
	array_of_students[13] = { "14", "Mateo Ivic", 1, {5, 2}, 4, 3, 14 };
	array_of_students[14] = { "15", "Antonio Katic", 1, {2, 1}, 2, 2, NULL };
	array_of_students[15] = { "16", "Mario Krolo", 1, {3, 4}, 2, 4, 13 };
	array_of_students[16] = { "17", "Tea Begonja", 0, {2, 5}, 3, 3, 13 };
	array_of_students[17] = { "18", "Ivica Lulic", 1, {1, 5}, 2, 5, NULL };
	array_of_students[18] = { "19", "Toma Maric", 1, {4, 5}, 4, 5, NULL };
	array_of_students[19] = { "20", "Matija Luketin", 1, {5, 5}, 5, 5, 20 };

	return array_of_students;
}

void print_menu() 
{
	cout << 
		"Choose action:\n" <<
		"(1)Add student\n" <<
		"(2)Remove student\n" <<
		"(3)Update student\n" <<
		"(4)View students\n" <<
		"(5)Calculate student's total\n" <<
		"(6)Best student\n" <<
		"(7)Worst student\n" <<
		"(8)Search by ID\n" <<
		"(9)Sort by total\n" <<
		"(0)Quit\n";
}

bool is_full(student *students, int n) 
{
	for (int i = 0; i < n; i++) {
		if (!strcmp("\0", students[i].id))
			return false;
	}
	return true;
}

bool is_completely_empty(student *students, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		if (strcmp("\0", students[i].id))
			return false;
	}
	return true;
}

bool id_in_array(student *students, char *id, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		if (!strcmp(students[i].id, id))
			return true;
	}
	return false;
}

int index_by_id(student *students, char *id, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		if (!strcmp(students[i].id, id))
			return i;
	}
	return -1;
}

void add_student(student **students, int n) 
{
	if (is_full(*students, n)) //checking if list is full
	{
		cout << "Max number of students already in class!\n\n";
		return;
	}

	cout << "Enter student ID\n";
	char id[3];
	cin >> id;

	if (id_in_array(*students, id, n)) //checking if id is already in array
	{
		cout << "Id already belongs to a student!\n\n";
		return;
	}

	char compare_null = '\0';
	int index = index_by_id(*students, &compare_null, n); //finding an empty spot in the array
	if (index == -1)
	{
		cout << "Error finding index!";
		return;
	}

	strcat((*students)[index].id, id);
	cout << "Enter student's full name\n";
	cin >> (*students)[index].name;
	cout << "Enter 1 for male, 0 for female\n";
	cin >> (*students)[index].gender;
	cout << "Enter the first quiz grade\n";
	cin >> (*students)[index].quiz_grades[0];
	cout << "Enter the second quiz grade\n";
	cin >> (*students)[index].quiz_grades[1];
	cout << "Enter the mid term grade\n";
	cin >> (*students)[index].quiz_grades[0];
	cout << "Enter the final grade\n";
	cin >> (*students)[index].quiz_grades[0];
}

void remove_student(student **students, int n, char id = '\0') // 2 arguments-remove prompt, 3 arguments-remove by id
{
	if (is_completely_empty(*students, n)) //checking if array is empty
	{
		cout << "There are no students to delete!\n\n";
		return;
	}

	
	if (id == '\0') //if remove is called with two arguments
	{
		cout << "Enter student ID\n";
		cin >> id;
	}

	if (!id_in_array(*students, &id, n)) //checking if id is taken
	{
		cout << "Id not found!\n\n";
		return;
	}

	int index = index_by_id(*students, &id, n); //getting index of the student to delete
	if (index == -1)
	{
		cout << "Error finding index!";
		return;
	}

	strcpy((*students)[index].name, "\0");
	strcpy((*students)[index].id, "\0");
	(*students)[index].gender = NULL;
	(*students)[index].quiz_grades[0] = NULL;
	(*students)[index].quiz_grades[1] = NULL;
	(*students)[index].mid_term_grade = NULL;
	(*students)[index].final_grade = NULL;
	(*students)[index].total_grade = NULL;
	cout << "Student removed!\n\n";
	return;	
}

void update_student(student **students, int n) 
{

	if (is_completely_empty(*students, n)) //checking if array is empty
	{
		cout << "There are no students to delete!\n\n";
		return;
	}
	
	cout << "Enter student ID\n";
	char id[3];
	cin >> id;

	if (!id_in_array(*students, id, n)) //checking if id is in array 
	{  
		cout << "Id not found!\n\n";
		return;
	}
	
	int index = index_by_id(*students, id, n); //getting index of the student to update
	if (index == -1) 
	{
		cout << "Error finding index!";
		return;
	}

	cout << "Enter student's full name\n";
	cin >> (*students)[index].name;
	cout << "Enter 1 for male, 0 for female\n";
	cin >> (*students)[index].gender;
	cout << "Enter the first quiz grade\n";
	cin >> (*students)[index].quiz_grades[0];
	cout << "Enter the second quiz grade\n";
	cin >> (*students)[index].quiz_grades[1];
	cout << "Enter the mid term grade\n";
	cin >> (*students)[index].quiz_grades[0];
	cout << "Enter the final grade\n";
	cin >> (*students)[index].quiz_grades[0];
	cout << "Student updated!\n\n";
}

void print_students(student *students, int high, int low = 0) //implemented with lower limit (default = 0) for reusability
{
	if (is_completely_empty(students, high)) 
	{
		cout << "There are no students to print!\n\n";
		return;
	}

	for (; low < high; low++)
	{
		if(strcmp(students[low].id, "\0"))
		{
			cout << "------------------------------------\n";
			cout << "Student:  " << students[low].id << "  " << students[low].name;

			(students[low].gender) ? (cout << "  Male") : (cout << "  Female"); //converting bool to string
			
			cout << "\nGrades:     " << students[low].quiz_grades[0] << "     " << students[low].quiz_grades[1] << "     " << students[low].mid_term_grade << "     " << students[low].final_grade << "\n";
			
			if (students[low].total_grade != 0) //only print total grade if one exists
				cout << "Total grade:   " << students[low].total_grade << "\n";
			cout << "------------------------------------\n";
		}
	}
}

void calculate_total_grade(student **students, int n) 
{
	cout << "Enter student ID\n";
	char id[3];
	cin >> id;

	if (!id_in_array(*students, id, n)) //checking if id is already in array 
	{
		cout << "Id not found!\n\n";
		return;
	}
	
	int index = index_by_id(*students, id, n); //getting index of the student to update
	if (index == -1)
	{
		cout << "Error finding index!";
		return;
	}
	
	(*students)[index].total_grade = (*students)[index].quiz_grades[1] + (*students)[index].quiz_grades[0]
								   + (*students)[index].mid_term_grade + (*students)[index].final_grade;

	cout << "Grade calculated!\n\n";
}

void print_best_student(student *students, int n) 
{
	int best_student_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].total_grade > students[best_student_index].total_grade) 
			best_student_index = i;
	}
	print_students(students, best_student_index + 1, best_student_index);
}

void print_worst_student(student *students, int n) 
{
	int worst_student_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].total_grade < students[worst_student_index].total_grade)
			worst_student_index = i;
	}
	print_students(students, worst_student_index + 1, worst_student_index);
}

void print_student_by_id(student *students, int n) 
{
	cout << "Enter student ID\n";
	char id[3];
	cin >> id;
	int index = index_by_id(students, id, n);
	print_students(students, index + 1, index);
}

void bubblesort_students_by_total(student *students, int n) 
{
	if (is_completely_empty(students, n)) {
		return;
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (students[i].total_grade < students[j].total_grade && i != j)
			{
				student tmp;
				tmp = students[i];
				students[i] = students[j];
				students[j] = tmp;
			}
		}
	}
	print_students(students, n);
}

int main()
{	 
	int max_students = 30;
	student *array_of_students = seed_students(max_students);

	int selection = 1;
	while (selection != 0) 
	{
		print_menu();
		cin >> selection;

		switch(selection) 
		{ 
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
				print_students(array_of_students, max_students);
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
				bubblesort_students_by_total(array_of_students, max_students); // not working
				break;
		}
	}
	return 0;
	system("pause");
}