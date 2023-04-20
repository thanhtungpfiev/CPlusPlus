// NamespaceExample.cpp : Defines the entry point for the application.
//

#include "NamespaceExample.h"

using namespace std;

int a = 10;

namespace private_namespace {
	int a = -10;
}

int main()
{
	cout << "Hello CMake." << endl;
	int a = 20;
	cout << "Variable a (local) = " << a << endl;
	cout << "Variable a (global) = " << ::a << endl;
	cout << "Variable a (private_namespce) = " << private_namespace::a << endl;

	cout << "New version" << endl;

	return 0;
}
