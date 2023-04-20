#include "Dog.h"

#include <iostream>

using namespace std;

Dog::Dog()
{
}

Dog::~Dog()
{
}

void Dog::eat(Flesh &flesh)
{
    cout << "Dog eats " << flesh.toString().c_str() << endl;
}