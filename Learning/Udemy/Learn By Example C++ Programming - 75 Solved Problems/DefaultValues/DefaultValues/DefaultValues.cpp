// DefaultValues.cpp : Defines the entry point for the application.
//

#include "DefaultValues.h"

using namespace std;

void print_3D_Coordinates(double x = 0, double y = 0, double z = 0)
{
	cout << "A point in 3-D space: x = " << x << " , y = " << y << " , z = " << z << endl;
}

double getPerimeter(double radius, double PI = 3.1415)
{
	return 2 * PI * radius;
}

double getPerimeter(double side1, double side2, double side3)
{
	return side1 + side2 + side3;
}

//double getPerimeter(double length, double breadth)
//{
//	return 2 * (length + breadth);
//}

int main()
{
	print_3D_Coordinates();
	print_3D_Coordinates(10);
	print_3D_Coordinates(10, 20);
	print_3D_Coordinates(10, 20, 30);

	double radius = 5;
	double triangleSide = 3;

	cout << "Perimeter of a circle of radius " << radius << " = " << getPerimeter(radius) << endl;
	cout << "Perimeter of a triangle of side " << triangleSide << " = " << getPerimeter(triangleSide, triangleSide, triangleSide) << endl;

	double squareSide = 3;
	cout << "Perimeter of a square of sides " << squareSide << " = "
		<< getPerimeter(squareSide, squareSide) << endl;
	return 0;
}
