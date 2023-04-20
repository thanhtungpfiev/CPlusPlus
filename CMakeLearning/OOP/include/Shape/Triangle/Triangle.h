/*
 * File: Triangle.h
 * Project: Triangle
 * File Created: Friday, 1st July 2022 5:27:24 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle();
    virtual ~Triangle();
    void areas();

private:

};

#endif