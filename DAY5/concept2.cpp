#include <iostream>
#include <vector>
#include <type_traits>

// #1. concept �����. 
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
	// T Ÿ���� "sizable_container" �䱸������ �����ϴ����� 
	// ������ �ð��� ����.
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