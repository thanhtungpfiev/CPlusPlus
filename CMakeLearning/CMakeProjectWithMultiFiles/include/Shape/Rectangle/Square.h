/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 30 - 6 - 2022
 *
 * class Square
 *
 * brief
 *
 *
 */
#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle
{
public:
    Square();

    // Shape interface
public:
    void print();
};

#endif // SQUARE_H
