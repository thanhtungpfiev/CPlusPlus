/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 11/4/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 ***********************************************************************/
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Food/Food.h"
#include "Food/Flesh.h"
#include "Animal/Animal.h"
#include "Animal/Dog.h"

using namespace std;

int main()
{
    cout << "Hello" << endl;
    unordered_map<int, int> ht;
    vector<int> v = {1, 2};
    cout << ht.size() << endl;
    int a = 7, b = 3, c = (a & b) + (a | b) + (a ^ b);
    cout << c << endl;
    Food food;
    cout << food.toString() << endl;
    Animal animal;
    animal.eat(food);
    Flesh flesh;
    Dog dog;
    dog.eat(flesh);
    return 0;
}
