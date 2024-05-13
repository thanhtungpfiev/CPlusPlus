#pragma once
class ComplexNumber
{
private:
	float realPart;
	float complexPart;

public:
	ComplexNumber();
	ComplexNumber(const ComplexNumber& rhs);
	void setMemberVariables(double r, double c);
	float getRealPart();
	float getComplexPart();
	void print();

};
