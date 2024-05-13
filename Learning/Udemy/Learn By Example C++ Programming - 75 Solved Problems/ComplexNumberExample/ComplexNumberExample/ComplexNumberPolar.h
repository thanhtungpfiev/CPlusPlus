#pragma once

class ComplexNumber;

class ComplexNumberPolar
{
private:
    float modulus;
    float argument;
public:
    ComplexNumberPolar(double r, double theta);

    float getModulus() const;
    void  setModulus(float r);

    float getArgument() const;
    void  setArgument(float theta);

    friend ComplexNumber addTwoComplexNumbers
    (const ComplexNumber& cart,
        const ComplexNumberPolar& polar);
};
