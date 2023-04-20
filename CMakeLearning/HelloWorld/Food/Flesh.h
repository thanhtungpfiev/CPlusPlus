#ifndef FLESH_H
#define FLESH_H

#include "Food.h"
#include <iostream>

class Flesh : public Food
{
public:
    Flesh();
    ~Flesh();
    std::string toString();

private:
};

#endif