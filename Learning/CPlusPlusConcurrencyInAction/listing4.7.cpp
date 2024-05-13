/*
 * File: listing4.7.cpp Passing arguments to a function with std::async
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Friday, 19th August 2022 5:12:47 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <future>

using namespace std;

struct X
{
    void foo(int, std::string const &){};
    std::string bar(std::string const &){};
};

X x;

auto f1 = std::async(&X::foo, &x, 42, "hello"); // Calls p->foo(42,"hello") where p is &x

auto f2 = std::async(&X::bar, x, "goodbye"); // Calls tmpx.bar("goodbye") where tmpx is a copy of x

struct Y
{
    double operator()(double){};
};

Y y;

auto f3 = std::async(Y(), 3.141);         // Calls tmpy(3.141) where tmpy is move-constructed from Y()
auto f4 = std::async(std::ref(y), 2.718); // Calls y(2.718)

X baz(X &){};
auto f5 = std::async(baz, std::ref(x)); // Calls baz(x)

class move_only
{
public:
    move_only(){};
    move_only(move_only &&){};
    move_only(move_only const &) = delete;
    move_only &operator=(move_only &&){};
    move_only &operator=(move_only const &) = delete;
    void operator()(){};
};

auto f6 = std::async(move_only()); // Calls tmp() where tmp is constructed from std::move(move_only())

auto f7 = std::async(std::launch::async, Y(), 1.2); // Run in new thread

auto f8 = std::async(std::launch::deferred, baz, std::ref(x)); // Run in wait() or get()

auto f9 = std::async(std::launch::deferred | std::launch::async, baz, std::ref(x)); // Implementation chooses

auto f10 = std::async(baz, std::ref(x)); // Implementation chooses

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    f8.wait();
    return 0;
}