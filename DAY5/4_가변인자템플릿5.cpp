#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 모든 요소를 꺼내고 싶다면
	// => args 에 있는 2번째 요소를 꺼내고 싶다 ==> 한번에 하는 방법은 없습니다

	// #1. 아래 3가지 방법중에서 한가지를 사용해야 합니다.

	// 1. pack expansion     - C++11
	// 2. recursion 유사 코드 - C++11
	// 3. fold expression    - C++17

	// # pack expansion
	// 모든 요소가 같은 타입이라는 보장이 있으면 배열에 담을수 있습니다.
	int x[] = { args... };

	// 요소의 타입이 다르면 tuple 에 담을수 있습니다.
	std::tuple<Types...> t = { args... };

}


int main()
{
	foo(1, 2, 3);
}

