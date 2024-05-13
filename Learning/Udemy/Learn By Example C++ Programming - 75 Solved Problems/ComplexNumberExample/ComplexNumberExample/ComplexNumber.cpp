#include "ComplexNumber.h"

#include<iostream>

using namespace std;

int ComplexNumber::numObjectsCreated = 0; // define the static variable
const double ComplexNumber::PI = 3.1415;

ComplexNumber::ComplexNumber() : realPart(0.0), complexPart(0.0)
{
	// increment the static variable keeping track of objects created
	numObjectsCreated++;
	cout << "No arg-constructor called" << endl;
}

ComplexNumber::ComplexNumber(double r, double c) : realPart(r), complexPart(c)
{
	// increment the static variable keeping track of objects created
	numObjectsCreated++;
	cout << "Inside the 2-arg constructor called" << endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& rhs) : realPart(rhs.realPart), complexPart(rhs.complexPart)
{
	// increment the static variable keeping track of objects created
	numObjectsCreated++;
	cout << "Inside the copy constructor called" << endl;
}

ComplexNumber::~ComplexNumber()
{
	cout << "Inside the destructor: realPart = " << realPart << " complexPart = " << complexPart << endl;
}

float ComplexNumber::getRealPart() const
{
	return realPart;
}

void ComplexNumber::setRealPart(float r)
{
	realPart = r;
}

float ComplexNumber::getComplexPart() const
{
	return complexPart;
}

void ComplexNumber::setComplexPart(float c)
{
	complexPart = c;
}
