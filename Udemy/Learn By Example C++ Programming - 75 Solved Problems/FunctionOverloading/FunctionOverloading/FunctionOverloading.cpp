// FunctionOverloading.cpp : Defines the entry point for the application.
//

#include "FunctionOverloading.h"

using namespace std;

double getArea(double radius)
{
	return 3.14 * radius * radius;
}

double getArea(double length, double breadth)
{
	return length * breadth;
}

int main()
{
	double radius = 5;
	double squareSide = 3;

	cout << "Area of a circle of radius " << radius << " = " << getArea(radius) << endl;
	cout << "Area of a square of length " << squareSide << " = " << getArea(squareSide, squareSide) << endl;
	return 0;
}
