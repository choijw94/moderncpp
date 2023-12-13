// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0; 받게 되면 f(arg) 는 에러
{								// => int 변수인 arg 는 포인터로 암시적 변환 안됨
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
	foo(0); // ok

//	chronometry(foo, 0); // foo(0) 의도지만, error
	chronometry(foo, nullptr); // ok..  std::nullptr_t 이므로 (1일차 소스 참고)
}
// 완벽한 전달 기술은 결국 템플릿 입니다.
// => 최종 전달 받는 함수의 인자가 포인터 인 경우, 0 사용하면 무조건 에러 입니다.
// => 0 대신 nullptr 사용하세요..








