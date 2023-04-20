/*
 * File: main.cpp
 * Project: HelloWorldTest
 * File Created: Tuesday, 5th July 2022 10:26:17 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <list>
#include <thread>

using namespace std;

class A
{
public:
    A()
    {
    }
    ~A()
    {
        cout << "Destroyed A" << endl;
    }
};

class B : public A
{
public:
    B()
    {
    }
    virtual ~B()
    {
        cout << "Destroyed B" << endl;
    }
};

class C : public B
{
public:
    C()
    {
    }
    ~C()
    {
        cout << "Destroyed C" << endl;
    }
};

class ConfigSingleton
{
public:
    static ConfigSingleton *getInstance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new ConfigSingleton();
        }
        return m_instance;
    }
    static void print()
    {

        cout << "ConfigSingleton::print()" << endl;
    }

private:
    ConfigSingleton(){};
    virtual ~ConfigSingleton(){};
    ConfigSingleton(const ConfigSingleton &other);
    ConfigSingleton &operator=(const ConfigSingleton &other);
    static ConfigSingleton *m_instance;
};

ConfigSingleton *ConfigSingleton::m_instance = nullptr;

class Observer
{
public:
    virtual void print() = 0;
};

class Subject
{
public:
    void attach(Observer *observer)
    {
        m_observers.push_back(observer);
    }
    void detach(Observer *observer)
    {
        m_observers.remove(observer);
    }
    void notifyEvent()
    {
        for (auto e : m_observers)
        {
            e->print();
        }
    }

private:
    std::list<Observer *> m_observers;
};

class Observer1 : public Observer
{
public:
    void print()
    {
        cout << "Observer1" << endl;
    }
};

class Observer2 : public Observer
{
public:
    void print()
    {
        cout << "Observer2" << endl;
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    char a[10] = {'H', 'e', 'l', 'l', 'W', 'o', 'r', 'l', 'd'};
    int *p = (int *)a;
    for (int i = 0; i < 10; ++i)
    {
        cout << hex << int(a[i]) << " ";
    }
    cout << endl;
    cout << hex << int(p[1]) << endl;
    cout << dec << int(p[1]) << endl;
    // A *c = new C();
    // C* c1 = new C();
    B *c2 = new C();
    // delete c;
    // delete c1;
    delete c2;
    ConfigSingleton::getInstance()->print();
    Observer *observer1 = new Observer1();
    Observer *observer2 = new Observer2();
    Subject s;
    s.attach(observer1);
    s.attach(observer2);
    s.notifyEvent();

    std::thread threadObj([]
                          {
            for(int i = 0; i < 10; i++)
                std::cout<<"Display Thread Executing"<<std::endl; });

    for (int i = 0; i < 10; i++)
        std::cout << "Display From Main Thread" << std::endl;

    threadObj.join();
    std::cout << "Exiting from Main Thread" << std::endl;
    return 0;
}