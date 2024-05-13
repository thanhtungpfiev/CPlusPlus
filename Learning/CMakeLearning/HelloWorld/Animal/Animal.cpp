/*
 * File: Animal.cpp
 * Project: HelloWorld
 * File Created: Thursday, 30th June 2022 1:57:09 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal()
{
}

Animal::~Animal()
{
}

void Animal::eat(Food &food)
{
    cout << "Animal eats " << food.toString().c_str() << endl;
}