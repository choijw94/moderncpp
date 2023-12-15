#include <iostream>

// recursion 
// 1. 모든 인자를 가변인자로 하지 말고
// 2. 1번째 인자는 독립된 인자(이름있는 변수) 로 받으세요

// 주의 : 아래 코드는 재귀 호출이 아닙니다
// main => foo(인자3개) => foo(인자2개) => foo(인자한개) => foo() 형태로 호출..
// => 즉, 모두 다른 함수 호출

void foo() {}

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value;

//	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()		==> 이 경우를 위해서 인자없는 foo 필요

	// C++17 부터는 아래 처럼 하면 "인자 없는 foo()" 는 필요 없습니다
	// => if constexpr 기술을 사용하려면 C++17 이상..
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A'); // value : 1,  args : 3.4,  'A'
}





