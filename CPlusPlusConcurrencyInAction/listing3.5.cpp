/*
 * File: listing3.5.cpp A fleshed-out class definition for a thread-safe stack
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Friday, 5th August 2022 5:14:06 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <exception>
#include <memory>
#include <mutex>
#include <stack>

using namespace std;

struct empty_stack : std::exception
{
    const char *what() const throw()
    {
        return "empty stack";
    };
};

template <typename T>
class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack() {}
    threadsafe_stack(const threadsafe_stack &other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }
    threadsafe_stack &operator=(const threadsafe_stack &) = delete;
    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    void pop(T &value)
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        value = data.top();
        data.pop();
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    threadsafe_stack<int> si;
    si.push(5);
    si.pop();
    if (!si.empty())
    {
        int x;
        si.pop(x);
    }
    return 0;
}