/*
 * File: listing3.7.cpp Using a lock hierarchy to prevent deadlock
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Wednesday, 10th August 2022 4:22:15 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <mutex>

using namespace std;

class hierarchial_mutex
{
public:
    explicit hierarchial_mutex(unsigned level)
    {
    }
    void lock()
    {
    }
    void unlock()
    {
    }
};

hierarchial_mutex high_level_mutex(100000);
hierarchial_mutex low_level_mutex(5000);

int do_low_level_stuff()
{
    return 42;
}

int low_level_func()
{
    std::lock_guard<hierarchial_mutex> lk(low_level_mutex);
    return do_low_level_stuff();
}

void high_level_stuff(int some_param)
{
}

void high_level_func()
{
    std::lock_guard<hierarchial_mutex> lk(high_level_mutex);
    high_level_stuff(low_level_func());
}

void thread_a()
{
    high_level_func();
}

hierarchial_mutex other_mutex(100);
void do_other_stuff()
{
}

void other_stuff()
{
    high_level_func();
    do_other_stuff();
}

void thread_b()
{
    std::lock_guard<hierarchial_mutex> lk(other_mutex);
    other_stuff();
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}