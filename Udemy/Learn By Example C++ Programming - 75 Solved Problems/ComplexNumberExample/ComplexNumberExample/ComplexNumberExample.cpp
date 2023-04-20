// ComplexNumberExample.cpp : Defines the entry point for the application.
//

#include "ComplexNumberExample.h"

#include <iostream>
#include <cmath>

#include "ComplexNumber.h"
#include "ComplexNumberPolar.h"

using namespace std;

ComplexNumber addTwoComplexNumbers
(const ComplexNumber& cart,
	const ComplexNumberPolar& polar)
{
	float realPart = polar.modulus * cos(polar.argument * ComplexNumber::PI / 180);
	float complexPart = polar.modulus * sin(polar.argument * ComplexNumber::PI / 180);

	ComplexNumber result(realPart + cart.realPart, complexPart + cart.complexPart);
	return result;

}

int main()
{
	cout << "Hello CMake." << endl;
	ComplexNumber cart(5, 5);
	ComplexNumberPolar polar(10, 45);

	ComplexNumber sumOfTwoComplexNumbers = addTwoComplexNumbers(cart, polar);

	cout << "Real part = " << sumOfTwoComplexNumbers.getRealPart()
		<< " Complex part = " << sumOfTwoComplexNumbers.getComplexPart() << endl;
	return 0;
}
