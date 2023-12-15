#include <iostream>
#include <vector>
#include <type_traits>

// #1. concept 만들기. 
template<typename T>
concept sizable_container = requires(T& c)
{
	c.resize(0);
	c.begin();
	c.end();
	typename T::value_type;
};

template<typename T>
void foo(T& c)
{
	// T 타입이 "sizable_container" 요구조건을 만족하는지를 
	// 컴파일 시간에 조사.
	bool b = sizable_container<T>;

	std::cout << b << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);

	int x[3] = { 1,2,3 };
	foo(x);
}