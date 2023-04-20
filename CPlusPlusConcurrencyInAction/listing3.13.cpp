/*
 * File: listing3.13.cpp Protecting a data structure with a boost::shared_mutex
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Tuesday, 16th August 2022 3:56:37 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <map>
#include <string>
#include <mutex>
#include <shared_mutex>

using namespace std;

class dns_entry
{
};

class dns_cache
{
    std::map<std::string, dns_entry> entries;
    std::shared_mutex entry_mutex;

public:
    dns_entry find_entry(const std::string &domain)
    {
        std::shared_lock<std::shared_mutex> lk(entry_mutex);
        std::map<std::string, dns_entry>::const_iterator const it = entries.find(domain);
        return (it == entries.end() ? dns_entry() : it->second);
    }

    void update_or_add_entry(std::string const &domain, dns_entry const &dns_details)
    {
        std::lock_guard<std::shared_mutex> lk(entry_mutex);
        entries[domain] = dns_details;
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}