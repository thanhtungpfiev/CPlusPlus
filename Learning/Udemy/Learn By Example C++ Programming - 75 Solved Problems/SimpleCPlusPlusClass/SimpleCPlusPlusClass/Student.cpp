#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(const char* name)
{
	cout << "Inside constructor: passed in string = " << name << endl;
	studentName = new char[50];
	strcpy(studentName, name);
	cout << "Initialized string to " << studentName << endl;
}

Student::~Student()
{
	cout << "Freeing up memory to string " << studentName << endl;
	delete[] studentName;
}
