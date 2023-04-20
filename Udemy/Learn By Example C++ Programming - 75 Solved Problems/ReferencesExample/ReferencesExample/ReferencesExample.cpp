// ReferencesExample.cpp : Defines the entry point for the application.
//

#include "ReferencesExample.h"

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	// calling the function
	int a = 5;
	int b = 10;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	swap(a, b);
	printf("a = %d, b = %d\n", a, b);

	return 0;
}
