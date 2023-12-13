#include <iostream>

template<typename T> void foo(T&& arg)
{
	std::cout << __FUNCSIG__ << std::endl;
}
int main()
{
	int n = 10;

	// 아래 주석 외워야 합니다.(시험문제)
	foo(n);  // T=int&,  T&&=int& && => int&,  foo(int& )
	foo(10); // T=int    T&&=int&&             foo(int&&)
}




