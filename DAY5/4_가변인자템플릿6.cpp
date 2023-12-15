#include <iostream>

// recursion 
// 1. 모든 인자를 가변인자로 하지 말고
// 2. 1번째 인자는 독립된 인자(이름있는 변수) 로 받으세요

void foo() {}

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value;

	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()		==> 이 경우를 위해서 인자없는 foo 필요
}

int main()
{
	foo(1, 3.4, 'A'); // value : 1,  args : 3.4,  'A'
}





