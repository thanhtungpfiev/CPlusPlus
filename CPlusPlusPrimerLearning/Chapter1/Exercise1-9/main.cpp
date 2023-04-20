/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 3/16/2022
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
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val;
        ++val;
    }
    cout << sum << endl;
    return 0;
}
