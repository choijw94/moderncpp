#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args �� �ִ� ��� ��Ҹ� ������ �ʹٸ�
	// => args �� �ִ� 2��° ��Ҹ� ������ �ʹ� ==> �ѹ��� �ϴ� ����� �����ϴ�

	// #1. �Ʒ� 3���� ����߿��� �Ѱ����� ����ؾ� �մϴ�.

	// 1. pack expansion     - C++11
	// 2. recursion ���� �ڵ� - C++11
	// 3. fold expression    - C++17

	// # pack expansion
	// ��� ��Ұ� ���� Ÿ���̶�� ������ ������ �迭�� ������ �ֽ��ϴ�.
	int x[] = { args... };

	// ����� Ÿ���� �ٸ��� tuple �� ������ �ֽ��ϴ�.
	std::tuple<Types...> t = { args... };

}


int main()
{
	foo(1, 2, 3);
}

