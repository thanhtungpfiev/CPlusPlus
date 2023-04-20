// SimpleCPlusPlusClass.cpp : Defines the entry point for the application.
//

#include "SimpleCPlusPlusClass.h"
#include "ComplexNumber.h"
#include "Student.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	ComplexNumber c;
	c.print();
	c.setMemberVariables(3.14, 5.3);
	c.print();
	ComplexNumber c1 = c;
	c1.print();


	char name[50] = "Dao Thanh Tung";
	Student st(name);
	cout << "End program" << endl;

	return 0;
}
