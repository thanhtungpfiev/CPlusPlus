/*
 * File: listing3.9.cpp
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Thursday, 11th August 2022 4:03:31 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <mutex>

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
        if (&lhs.m == &rhs.m)
        {
            return;
        }
        std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
        std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
        std::lock(lock_a, lock_b);
        swap(lhs.some_detail, rhs.some_detail);
    }
};

int main(int argc, char **argv)
{
    return 0;
}