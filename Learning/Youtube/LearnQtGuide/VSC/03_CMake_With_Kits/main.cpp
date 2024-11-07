#include <compare>
#include <iostream>
#include <set>
#include <fmt/format.h>
#include "person.h"

struct Point
{
    int x;
    int y;
    auto operator<=>(const Point&) const = default;
    // ... non-comparison functions ...
};
// compiler generates all six two-way comparison operators

int main()
{
    int value { 5 };
    Point pt1{1, 1}, pt2{1, 2};
    std::set<Point> s; // OK
    s.insert(pt1);     // OK
 
    std::cout << std::boolalpha
        << (pt1 == pt2) << ' '  // false; operator== is implicitly defaulted.
        << (pt1 != pt2) << ' '  // true
        << (pt1 <  pt2) << ' '  // true
        << (pt1 <= pt2) << ' '  // true
        << (pt1 >  pt2) << ' '  // false
        << (pt1 >= pt2) << ' '; // false
    
    std::cout << std::endl;

    fmt::println("The value is: {}", value);
    fmt::println("The sky is blue my friend!");

    Person p;
    p.eat();
    
    return 0;
}