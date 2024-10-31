// Factorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

const int MAX = 1000;
int dem[MAX];

void xu_ly_1_thua_so(int n)
{
	for (int i = 2; i <= n; i++) {
		while (n % i == 0) {
			++dem[i];
			n /= i;
		}
	}
}
int main() {
	int N;
	cout << "\nNhap n = ";
	cin >> N;
	int n = N; // Tao ban sao cua N
	if (n > MAX) {
		printf("Ban nhap so lon hon %d", MAX);
		return 0;
	}
	for (int i = 0; i <= n; i++) dem[i] = 0;
	for (int i = 2; i <= n; i++) {
		xu_ly_1_thua_so(i);
	}
	for (int i = 0; i <= N; i++) {
		if (dem[i]) {
			cout << dem[i] << " ";
		}
	}
	cout << endl;
}
