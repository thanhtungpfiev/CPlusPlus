/*
 * File: listing4.6.cpp Using std::future to get the return value of an asynchronous task
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Friday, 19th August 2022 5:02:29 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <future>

using namespace std;

int find_the_answer_to_ltuae()
{
    return 42;
}
void do_other_stuff()
{
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    std::cout << "The answer is " << the_answer.get() << std::endl;
    return 0;
}