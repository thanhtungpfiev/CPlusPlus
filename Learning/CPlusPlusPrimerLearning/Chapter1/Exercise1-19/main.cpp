/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 3/17/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int v1 = 0, v2 = 0;
    cout << "Enter 2 integer numbers: "  << endl;
    cin >> v1 >> v2;
    if (v1 > v2) {
        cout << "Invalid input. Please input first number is smaller than the second" << endl;
    } else {
        cout << "each number in the range specified by " << v1 << " and " << v2 << " :" << endl;
        int val = v1;
        while (val <= v2) {
            cout << val << " ";
            ++val;
        }
        cout << endl;
    }
    return 0;
}
