#include <iostream>

int hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

template<typename ... Types> 
void foo(Types ... args)
{
	// #1. parameter pack �̶�� ��� �˾� �μ���
	// foo(1, 2, 3) ���� ���� 
	// Types : int, int, int	=> template parameter pack
	// args  : 1,   2,   3		=> function parameter pack

	// #2. sizeof...(pack) : pack ���� ����� ���� 
	std::cout << sizeof...(args)  << std::endl; // 3
	std::cout << sizeof...(Types) << std::endl; // 3
}


int main()
{
	foo(1, 2, 3);
}
