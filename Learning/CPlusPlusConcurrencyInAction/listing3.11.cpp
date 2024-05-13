/*
 * File: listing3.11.cpp Thread-safe lazy initialization using a mutex
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Tuesday, 16th August 2022 3:09:11 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

struct some_resource
{
    void do_something() {}
};

std::shared_ptr<some_resource> resource_ptr;
std::mutex resource_mutex;

void foo()
{
    std::unique_lock<std::mutex> lk(resource_mutex);
    if (!resource_ptr) {
        resource_ptr.reset(new some_resource);
    }
    lk.unlock();
    resource_ptr->do_something();
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    foo();
    return 0;
}