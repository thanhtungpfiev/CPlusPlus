#ifndef DOG_H
#define DOG_H

#include "../Food/Flesh.h"
#include "Animal.h"

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
    void eat(Flesh &flesh);

private:
};

#endif