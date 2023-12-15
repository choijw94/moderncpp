#include <iostream>
#include <vector>
#include <type_traits>

// #1. concept 만들기. 
template<typename T>
concept sizable_container = requires(T & c)
{
	c.resize(0);
	c.begin();
	c.end();
	typename T::value_type;
};

// requires clauses
// => 조건을 만족하는 경우만 사용
template<typename T> requires sizable_container<T>
void foo(T& c)
{
	std::cout << "sizable\n";
}

// 위와 동일
template<sizable_container T> 
void goo(T& c)
{
	std::cout << "sizable\n";
}

// 위와 동일
void hoo(sizable_container auto& c)
{
	std::cout << "sizable\n";
}

int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);
}