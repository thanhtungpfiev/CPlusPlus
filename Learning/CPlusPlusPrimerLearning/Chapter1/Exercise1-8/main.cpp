#include <iostream>

using namespace std;

int main()
{
    std::cout << "/*";
    std::cout << "*/";
//    std::cout << /* "*/" */; => Not Ok because of missing operands
//    std::cout << /* "*/" /* "/*" */; => Not Ok because of nested pair comment
    return 0;
}
