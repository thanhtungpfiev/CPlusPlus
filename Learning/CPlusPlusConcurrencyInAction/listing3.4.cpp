/*
 * File: listing3.4.cpp An outline class definition for a thread-safe stack
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Friday, 5th August 2022 5:10:08 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <exception>
#include <memory>

using namespace std;

struct empty_stack : std::exception
{
    const char *what() const throw();
};

template <typename T>
class threadsafe_stack
{
public:
    threadsafe_stack();
    threadsafe_stack(const threadsafe_stack &);
    threadsafe_stack &operator=(const threadsafe_stack &) = delete;

    void push(T new_value);
    std::shared_ptr<T> pop();
    void pop(T &value);
    bool empty() const;
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}