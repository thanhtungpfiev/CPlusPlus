/*
 * File: listing3.1.cpp Protecting a list with a mutex
 * Project: ccia_code_samples-master
 * File Created: Tuesday, 2nd August 2022 5:38:15 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <mutex>

using namespace std;

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    add_to_list(42);
    std::cout << "contains(1) = " << list_contains(1) << ", contains(42) = " << list_contains(42) << std::endl;
    return 0;
}