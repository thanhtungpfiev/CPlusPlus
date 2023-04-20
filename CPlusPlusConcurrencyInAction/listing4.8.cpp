/*
 * File: listing4.8.cpp Partial class definition for a specialization of std::packaged_task< >
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Monday, 22nd August 2022 5:10:07 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <string>
#include <vector>
#include <future>

using namespace std;

template <>
class packaged_task<std::string(std::vector<char> *, int)>
{
public:
    template <typename Callable>
    explicit packaged_task(Callable &&f);
    std::future<std::string> get_future();
    void operator()(std::vector<char> *, int);
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}