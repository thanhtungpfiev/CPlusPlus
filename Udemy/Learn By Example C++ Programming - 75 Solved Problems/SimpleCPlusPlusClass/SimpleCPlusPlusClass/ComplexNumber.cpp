#include "ComplexNumber.h"

#include <iostream>

using namespace std;

ComplexNumber::ComplexNumber() : realPart(0.0), complexPart(0.0)
{
	cout << "No arg-constructor called" << endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& rhs) : realPart(rhs.realPart), complexPart(rhs.complexPart)
{
	cout << "Inside the copy construtor" << endl;
}

void ComplexNumber::setMemberVariables(double r, double c)
{
	realPart = r;
	complexPart = c;
}

float ComplexNumber::getRealPart()
{
	return realPart;
}

float ComplexNumber::getComplexPart()
{
	return complexPart;
}

void ComplexNumber::print()
{
	cout << "real = " << realPart << " complex = " << complexPart << endl;
}
