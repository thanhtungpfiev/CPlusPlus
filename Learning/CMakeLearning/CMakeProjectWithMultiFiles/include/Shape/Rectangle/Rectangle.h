/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 30 - 6 - 2022
 *
 * class Rectangle
 *
 * brief
 *
 *
 */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"


class Rectangle : public Shape
{
public:
    Rectangle();

    // Shape interface
public:
    void print();
};

#endif // RECTANGLE_H
