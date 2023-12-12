#include <iostream>

int main()
{
	int x[3] = { 1,2,3 };

	// ¹è¿­°ú auto, decltype

	auto  a1 = x;	// int* a1 = x;
	auto& a2 = x;   // int(&a2)[3] = x;

	decltype(x) d;	// int d[3];
}