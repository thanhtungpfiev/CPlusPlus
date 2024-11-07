#include <compare>
#include <iostream>
#include <set>

#include "person.h"
 
struct Point
{
    int x;
    int y;
    auto operator<=>(const Point&) const = default;
    /* non-comparison functions */
};
 
int main()
{
    Point pt1{1, 1}, pt2{1, 2};
    std::set<Point> s; // OK
    s.insert(pt1);     // OK
 
    // two-way comparison operator functions are not required to be explicitly defined:
    // operator== is implicitly declared (see below)
    // the overload resolutions of other candidates will select rewritten candidates 
    std::cout << std::boolalpha
        << (pt1 == pt2) << ' '  // false
        << (pt1 != pt2) << ' '  // true
        << (pt1 <  pt2) << ' '  // true
        << (pt1 <= pt2) << ' '  // true
        << (pt1 >  pt2) << ' '  // false
        << (pt1 >= pt2) << ' '; // false

    std::cout << std::endl;
    Person p;
    p.eat();
}