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
	// => type traits 기술
	// => 대부분 template partial specialization 기술로 만들게 됩니다.
	bool b = std::is_pointer_v<T>;


	// T 가 size 변경이 가능한 컨테이너인지 알고 싶다.
	// => template partial specialization 로 만들기는 힘들다.
	// => 새로운 문법을 도입하자.!! - C++20 concept
}
int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);
}