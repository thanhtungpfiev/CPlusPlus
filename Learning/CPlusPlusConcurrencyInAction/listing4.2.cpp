/*
 * File: listing4.2.cpp std::queue interface
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Thursday, 18th August 2022 4:00:47 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <deque>

using namespace std;

template <class T, class Container = std::deque<T>>

class queue
{
public:
    explicit queue(const Container &);
    explicit queue(const Container && = Container());
    queue(queue &&q);

    template <class Alloc>
    explicit queue(const Alloc &);
    template <class Alloc>
    explicit queue(const Container &, const Alloc &);
    template <class Alloc>
    explicit queue(Container &&, const Alloc &);

    queue &operator=(queue &&q);
    void swap(queue &&q);

    bool empty() const;
    typedef typename std::deque<T>::size_type size_type;
    size_type size() const;

    T &front();
    const T &front() const;
    T &back();
    const T &back() const;

    void push(const T &x);
    void push(T &&x);
    void pop();
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}