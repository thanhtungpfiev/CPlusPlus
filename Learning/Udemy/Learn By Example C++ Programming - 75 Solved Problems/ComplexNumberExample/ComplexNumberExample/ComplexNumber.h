#pragma once

class ComplexNumberPolar;

class ComplexNumber
{
private:
	float realPart;
	float complexPart;
	static int numObjectsCreated;

public:
	const static double PI;
	ComplexNumber();
	ComplexNumber(double r, double c);
	ComplexNumber(const ComplexNumber& rhs);
	~ComplexNumber();

	float getRealPart() const;
	void setRealPart(float r);
	float getComplexPart() const;
	void setComplexPart(float c);

	friend ComplexNumber addTwoComplexNumbers(const ComplexNumber& cart, const ComplexNumberPolar& polar);
};
