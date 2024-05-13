/*
 * File: listing4.3.cpp The interface of your threadsafe_queue
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Thursday, 18th August 2022 4:10:33 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <memory>

using namespace std;

template <typename T>

class threadsafe_queue
{
public:
    threadsafe_queue();
    threadsafe_queue(const threadsafe_queue &);
    threadsafe_queue &operator=(const threadsafe_queue &) = delete;

    void push(T new_value);

    bool try_pop(T &value);
    std::shared_ptr<T> try_pop();

    void wait_and_pop(T &value);
    std::shared_ptr<T> wait_and_pop();

    bool empty() const;
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}