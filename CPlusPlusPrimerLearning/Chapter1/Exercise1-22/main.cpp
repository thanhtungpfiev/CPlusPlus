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
#include "Sales_item.h"

using namespace std;

int main()
{
    Sales_item sum, item;
    while (cin >> item) {
        sum += item;
    }
    cout << sum << endl;
    return 0;
}
