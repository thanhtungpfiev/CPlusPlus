/*
 * File: main.cpp
 * Project: OOP
 * File Created: Friday, 1st July 2022 1:46:03 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include "include/Shape/Shape.h"
#include "include/Shape/Triangle/Triangle.h"

using namespace std;

int main(int argc, char **argv)
{
    Triangle *triangle = new Triangle();
    triangle->areas();
    std::cout << "Hello, world!\n";
    delete triangle;
    return 0;
}
