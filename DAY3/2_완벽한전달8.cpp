#include <iostream>

int& foo(int& a) { return a; }

// 1. 리턴값도 완벽히 돌려주고 싶다면, "decltype(auto)" 를 사용하세요.

template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg)
{
	return f(std::forward<T>(arg));
}

int main()
{
	int n = 3;

	int& ret = chronometry(foo, n); // foo(n) 

	ret = 200; // n = 200 의미

	std::cout << n << std::endl; // 200

}
