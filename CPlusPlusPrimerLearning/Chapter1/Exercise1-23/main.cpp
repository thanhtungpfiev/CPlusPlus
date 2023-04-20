/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 17 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include "Sales_item.h"

using namespace std;

int main()
{
    Sales_item curr_item, item;
    if (cin >> curr_item)
    {
        int cnt = 1;
        while (cin >> item) {
            if (item.isbn() == curr_item.isbn()) {
                cnt++;
            } else {
                cout << curr_item.isbn() << ": " << cnt << endl;
                curr_item = item;
                cnt = 1;
            }
        }
        cout << curr_item.isbn() << ": " << cnt << endl;
    }
    return 0;
}
