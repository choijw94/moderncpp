#include <iostream>

// auto 와 람다 표현식

int main()
{
//	int foo() {} // 함수 안에 함수, local function, nested function 이라고 합니다

	// #1. 람다표현식을 auto 변수에 담아서 함수 처럼 사용가능합니다.
	// => 일부 언어(C#등)는 함수 안에 함수를 만들수 있습니다.
	// => C++ 은 함수 안에 함수를 만들수 없는데
	//    아래 처럼 만들면 결국, local function 을 만든것과 동일합니다.

	auto add = [](int a, int b) { return a + b; };
				// class ClosureType{ operator()(){} }; ClosureType();

	int n1 = add(1, 2);
	int n2 = add.operator()(1, 2); // ok..
}

