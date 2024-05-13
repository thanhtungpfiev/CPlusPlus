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
    int currVal = 0, val = 0;
    if (cin >> currVal) {
        int cnt = 1;
        while (cin >> val) {
            if (val == currVal) {
                ++cnt;
            } else {
                cout << currVal << " occurs " << cnt << " times" << endl;
                currVal = val;
                cnt = 1;
            }
        }
        cout << currVal << " occurs " << cnt << " times" << endl;
    }
    return 0;
}
