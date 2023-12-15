// concept1
#include <iostream>
#include <vector>
#include <type_traits>

// C++11 핵심 기술 : move, perfect forwarding, lambda 등...
// C++20           : concept, coroutine, ranges, module 등

template<typename T>
void foo(T& c)
{
	// T 가 포인터 인지 알고 싶다.
	bool b = std::is_pointer_v<T>;

	// T 가 size 변경이 가능한 컨테이너인지 알고 싶다.
	// ?
}
int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);
}