/**
 * person.cpp
 */

#include "person.hpp"

gtestbox::person::Person::Person() :
    name("unknown"),
    age(0) {}

void gtestbox::person::Person::sayHello(std::string msg) {
    std::cout << this->name << ", age " << this->age << ", says '" << msg << "'" << std::endl;
    if (msg.length() > 3 && msg.length() < 5)
    {
        std::cout << "Hit" << std::endl;
    }
    else
    {
        std::cout << "No Hit" << std::endl;
    }
}