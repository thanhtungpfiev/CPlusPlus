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
    Sales_item item;
    while (cin >> item) {
        cout << item << endl;
    }
    return 0;
}
