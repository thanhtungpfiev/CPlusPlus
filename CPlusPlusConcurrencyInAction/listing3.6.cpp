/*
 * File: listing3.6.cpp Using std::lock() and std::lock_guard in a swap operation
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Monday, 8th August 2022 5:42:37 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <mutex>

using namespace std;

class some_big_object
{
};

void swap(some_big_object &lhs, some_big_object &rhs)
{
}

class X
{
private:
    some_big_object some_detail;
    mutable std::mutex m;

public:
    X(some_big_object const &sd) : some_detail(sd) {}

    friend void swap(X &lhs, X &rhs)
    {
        if (&lhs == &rhs)
        {
            return;
        }
        std::lock(lhs.m, rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        swap(lhs.some_detail, rhs.some_detail);
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}