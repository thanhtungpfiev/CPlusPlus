/*
 * File: Animal.h
 * Project: HelloWorld
 * File Created: Thursday, 30th June 2022 1:57:09 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#ifndef ANIMAL_H
#define ANIMAL_H

#include "../Food/Food.h"

class Animal
{
public:
    Animal();
    ~Animal();
    virtual void eat(Food &food);

private:

};

#endif