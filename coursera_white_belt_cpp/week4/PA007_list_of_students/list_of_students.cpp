#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Student {
	string name;
	string surname;
	int day = 0;
	int month = 0;
	int year = 0;
};

int main() {
	int number_of_students;
	cin >> number_of_students;
	vector<Student> STUDENTS;
	while (number_of_students > 0) {
		--number_of_students;
		Student student;
		cin >> student.name >> student.surname >> student.day >> student.month >> student.year;
		STUDENTS.push_back(student);
	}
	int number_of_operations;
	cin >> number_of_operations;
	while (number_of_operations > 0) {
		--number_of_operations;
		string operation;
		cin >> operation;
		int number;
		cin >> number;
		if (operation == "name" && number > 0 && number <= STUDENTS.size()) {
			cout << STUDENTS[number - 1].name << " " << STUDENTS[number - 1].surname << "\n";
		}
		else if (operation == "date" && number > 0 && number <= STUDENTS.size()) {			
			cout << STUDENTS[number - 1].day << "." << STUDENTS[number - 1].month << "." << STUDENTS[number - 1].year << "\n";
		}
		else cout << "bad request\n";

	}
	return 0;
}



