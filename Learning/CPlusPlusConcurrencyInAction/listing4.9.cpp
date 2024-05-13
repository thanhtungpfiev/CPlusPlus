/*
 * File: listing4.9.cpp
 * Project: CPlusPlusConcurrencyInAction Running code on a GUI thread using std::packaged_task
 * File Created: Monday, 22nd August 2022 5:15:30 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>

using namespace std;

std::mutex m;
std::deque<std::packaged_task<void()>> tasks;

bool gui_shutdown_message_received(){};viet
void get_and_process_gui_message(){};

void gui_thread()
{
    while (!gui_shutdown_message_received())
    {
        get_and_process_gui_message();
        std::packaged_task<void()> task;
        {
            std::lock_guard<std::mutex> lk(m);
            if (tasks.empty())
            {
                continue;
            }
            task = std::move(tasks.front());
            tasks.pop_front();
        }
        task();
    }
}

std::thread gui_bg_thread(gui_thread);

template <typename Func>
std::future<void> post_task_for_gui_thread(Func f)
{
    std::packaged_task<void()> task(f);
    std::future<void> res = task.get_future();
    std::lock_guard<std::mutex> lk(m);
    tasks.push_back(std::move(task));
    return res;
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}