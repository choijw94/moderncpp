#include <iostream>
#include <vector>
#include <type_traits>

// #1. concept �����. 
template<typename T>
concept sizable_container = requires(T & c)
{
	c.resize(0);
	c.begin();
	c.end();
	typename T::value_type;
};

// requires clauses
// => ������ �����ϴ� ��츸 ���
template<typename T> requires sizable_container<T>
void foo(T& c)
{
	std::cout << "sizable\n";
}

// ���� ����
template<sizable_container T> 
void goo(T& c)
{
	std::cout << "sizable\n";
}

// ���� ����
void hoo(sizable_container auto& c)
{
	std::cout << "sizable\n";
}

int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);
}