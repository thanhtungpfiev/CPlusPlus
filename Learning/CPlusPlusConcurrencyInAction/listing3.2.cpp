/*
 * File: listing3.2.cpp  Accidentally passing out a reference to protected data
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Tuesday, 2nd August 2022 5:56:07 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <mutex>

using namespace std;

class some_data
{
    int a;
    std::string b;

public:
    void do_something()
    {
    }
};

class data_wrapper
{
private:
    some_data data;
    std::mutex m;

public:
    template <typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> l(m);
        func(data);
    }
};

some_data *unprotected;

void malicious_function(some_data &protected_data)
{
    unprotected = &protected_data;
}

data_wrapper x;

void foo()
{
    x.process_data(malicious_function);
    unprotected->do_something();
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    foo();
    return 0;
}