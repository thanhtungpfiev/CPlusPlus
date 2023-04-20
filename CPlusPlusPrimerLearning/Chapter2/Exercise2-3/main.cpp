/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 20 - 3 - 2022
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
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl;
    cout << u - u2 << endl; // -32 convert to unsigned int which very large

    int i = 10, i2 = 42;
    cout << i2 - i << endl;
    cout << i - i2 << endl; // -32, i front of i2 so result convert to int

    cout << i - u << endl;
    cout << u - i << endl;
    return 0;
}
