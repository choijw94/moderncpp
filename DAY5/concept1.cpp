// concept1
#include <iostream>
#include <vector>
#include <type_traits>

// C++11 �ٽ� ��� : move, perfect forwarding, lambda ��...
// C++20           : concept, coroutine, ranges, module ��

template<typename T>
void foo(T& c)
{
	// T �� ������ ���� �˰� �ʹ�.
	bool b = std::is_pointer_v<T>;

	// T �� size ������ ������ �����̳����� �˰� �ʹ�.
	// ?
}
int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);
}