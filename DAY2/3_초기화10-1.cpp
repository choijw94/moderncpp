#include <iostream>
#include <initializer_list>

int g = 10;
std::initializer_list<int> gi = { 1,2,3,4 };

int main()
{
	int n = 10;
	std::initializer_list<int> ni = { 1,2,3,4 };

	printf("%p\n", &g);
	printf("%p\n", &(*(gi.begin())));
	printf("%p\n", &n);
	printf("%p\n", &(*(ni.begin())));

}