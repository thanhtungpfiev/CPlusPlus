/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 3/17/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>

using namespace std;

//Syntax errors: The programmer has made a grammatical error in the C++ language.
//The following program illustrates common syntax errors; each comment describes the
//error on the following line:
//// error: missing ) in parameter list for main
//int main ( {
//// error: used colon, not a semicolon, after endl
//std::cout << "Read each file." << std::endl:
//// error: missing quotes around string literal
//std::cout << Update master. << std::endl;
//// error: second output operator is missing
//std::cout << "Write new master." std::endl;
//// error: missing ; on return statement
//return 0
//}

//Type errors: Each item of data in C++ has an associated type. The value 10, for example,
//has a type of int (or, more colloquially, “is an int”). The word "hello", including
//the double quotation marks, is a string literal. One example of a type error is passing
//a string literal to a function that expects an int argument.

//Declaration errors: Every name used in a C++ program must be declared before it is
//used. Failure to declare a name usually results in an error message. The two most
//common declaration errors are forgetting to use std:: for a name from the library
//and misspelling the name of an identifier:
//#include <iostream>
//int main()
//{
//    int v1 = 0, v2 = 0;
//    std::cin >> v >> v2; // error: uses "v" not "v1"
//    // error: cout not defined; should be std::cout
//    cout << v1 + v2 << std::endl;
//    return 0;
//}

int main()
{
    std::cout << "Read each file." << std::endl;
    std::cout << "Update master." << std::endl;
    std::cout << "Write new master." << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << v1 + v2 << std::endl;
    return 0;
}
