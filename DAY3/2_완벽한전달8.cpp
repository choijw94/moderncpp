#include <iostream>

int& foo(int& a) { return a; }

// 1. ���ϰ��� �Ϻ��� �����ְ� �ʹٸ�, "decltype(auto)" �� ����ϼ���.

template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg)
{
	return f(std::forward<T>(arg));
}

int main()
{
	int n = 3;

	int& ret = chronometry(foo, n); // foo(n) 

	ret = 200; // n = 200 �ǹ�

	std::cout << n << std::endl; // 200

}
