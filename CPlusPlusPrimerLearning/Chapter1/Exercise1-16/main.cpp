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
    int sum = 0, val = 0;
    while (cin >> val) {
        sum += val;
    }
    cout << sum << endl;
    return 0;
}
