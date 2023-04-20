/*
 * File: listing3.8.cpp A simple hierarchical mutex
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Wednesday, 10th August 2022 5:10:39 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <mutex>
#include <stdexcept>
#include <climits>

class hierarchial_mutex
{
    std::mutex internal_mutex;
    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;
    static thread_local unsigned long this_thread_hierarchy_value;

    void check_for_hierarchy_violation()
    {
        if (this_thread_hierarchy_value <= hierarchy_value)
        {
            throw std::logic_error("mutex hierarchy violated");
        }
    }
    void update_hierarchy_value()
    {
        previous_hierarchy_value = this_thread_hierarchy_value;
        this_thread_hierarchy_value = hierarchy_value;
    }

public:
    explicit hierarchial_mutex(unsigned long value) : hierarchy_value(value), previous_hierarchy_value(0) {}

    void lock()
    {
        check_for_hierarchy_violation();
        internal_mutex.lock();
        update_hierarchy_value();
    }
    void unlock()
    {
        this_thread_hierarchy_value = previous_hierarchy_value;
        internal_mutex.unlock();
    }
    bool try_lock()
    {
        check_for_hierarchy_violation();
        if (!internal_mutex.try_lock())
        {
            return false;
        }
        update_hierarchy_value();
        return true;
    }
};

thread_local unsigned long hierarchial_mutex::this_thread_hierarchy_value(ULONG_MAX);

int main(int argc, char **argv)
{
    hierarchial_mutex m1(42);
    hierarchial_mutex m2(2000);
}