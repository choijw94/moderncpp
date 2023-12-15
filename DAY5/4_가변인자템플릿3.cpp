#include <iostream>

int hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

template<typename ... Types> 
void foo(Types ... args)
{
	// #1. parameter pack 이라는 용어 알아 두세요
	// foo(1, 2, 3) 으로 사용시 
	// Types : int, int, int	=> template parameter pack
	// args  : 1,   2,   3		=> function parameter pack

	// #2. sizeof...(pack) : pack 안의 요소의 갯수 
	std::cout << sizeof...(args)  << std::endl; // 3
	std::cout << sizeof...(Types) << std::endl; // 3
}


int main()
{
	foo(1, 2, 3);
}
