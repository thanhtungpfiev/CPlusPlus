/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 23 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>

using namespace std;

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    r2 = 3.14159;
    r2 = r1;
    i = r2;
    r1 = d;
    return 0;
}
