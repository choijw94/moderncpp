// 8_nullptr2
#include <iostream>

void foo(int* p) {}

// 인자로 "함수"와 "인자"를 받아서
// => "함수(인자)" 형태로 호출하는 함수
template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)	// int arg = 0; 
{
	f(arg); // int arg 였다면 error.
}

int main()
{
	foo(0); // ok
//	forward_parameter(foo, 0);	// foo(0) 의 의도 이지만 error 입니다.
								// 0 자체는 literal 이므로 포인터로 변환 되지만
								// forward_parameter 가 받을때 "int arg = 0"
								// 이 되므로 arg 는 포인터로 암시적 변환 안됨.

	forward_parameter(foo, nullptr); // ok

}








