/*
 * File: listing3.3.cpp
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Thursday, 4th August 2022 5:01:42 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <deque>
#include <cstddef>

using namespace std;

template <typename T, typename Container = std::deque<T>>

class stack
{
public:
    explicit stack(const Container &);
    explicit stack(Container && = Container());
    template <class Alloc>
    explicit stack(const Alloc &);
    template <class Alloc>
    stack(const Container &, const Alloc &);
    template <class Alloc>
    stack(Container &&, const Alloc &);
    template <class Alloc> stack(stack&&, const Alloc&);
    bool empty() const;
    size_t size() const;
    T& top();
    T const& top() const;
    void push(T const&);
    void push(T&&);
    void pop();
    void swap(stack&&);
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}