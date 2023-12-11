#include <iostream>

// T의 타입조사하는 방법
template<typename T> void foo(T a)
{
	// #1. RTTI 기술 사용
	std::cout << typeid(T).name() << std::endl;
}

int main()
{
	// #1. 타입인자를 명시적으로 전달하는 경우
	// => 사용자가 전달한 타입 사용
	foo<int>(3.4); // T = int

	
	// #2. 타입인자를 전달하지 않은 경우. 
	// => 함수 인자를 사용해서 T 의 타입을 결정
	foo(10); // T = int 
	foo(3.4);// T = double

}