#include <iostream>

int& foo(int& a) { return a; }

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}


int main()
{
	int n = 3;

	int& ret = chronometry(foo, n); // foo(n) 

	ret = 200;

	std::cout << n << std::endl;

}
