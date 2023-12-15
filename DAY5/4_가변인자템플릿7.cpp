#include <iostream>

// ���� �������� ���ø��� ����ϳ��� ??
// => �������� ���ø��� ����ϴ� ���������� �������� �ֽ��ϴ�.

// 1. �Ϻ��� ������ ����ϴ� �ڵ�� ��κ� �������� ���ø� ���
// 2. std::tuple, std::get ���� �ڵ�� �������� ���ø����� ����� �˴ϴ�.

void foo(int a, int b, int& c) { c = 100; }

/*
// �Ʒ� ó�� �����, chronometry �� ���ڰ� �Ѱ��� �Լ��� forwarding �����մϴ�.
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f( std::forward<T>(arg)); 
}
*/

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
//	return f( std::forward<T>(arg...) ); // forward(E1, E2, E3) �ε�
										 // forward �� ���ڰ� �Ѱ��� �Լ�

	return f(std::forward<Types>(arg)... );
			// f( std::forward<T1>(E1), 
			//	  std::forward<T2>(E2),
			//    std::forward<T3>(E3) );
}



int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

