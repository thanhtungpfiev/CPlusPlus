/*
 * File: main.cpp
 * Project: PartitionArraySuchThatMaximumDifferenceIsK
 * File Created: Sunday, 5th June 2022 12:58:52 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "include/Shape/Triangle/Triangle.h"
#include "include/Shape/Rectangle/Rectangle.h"
#include "include/Shape/Rectangle/Square.h"

using namespace std;

int main(int argc, char **argv)
{
    Triangle triangle;
    triangle.print();
    Square square;
    square.print();
    Rectangle rectangle;
    rectangle.print();
    Shape *s1 = new Triangle();
    Shape *s2 = new Rectangle();
    Shape *s3 = new Square();
    vector<Shape*> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    for (const auto &e : v) {
        e->print();
    }
    return 0;
}
