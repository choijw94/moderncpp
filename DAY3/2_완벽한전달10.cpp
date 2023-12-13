#include <iostream>
#include "stopwatch.h"	// git 에서 받으세요
						// DAY3 폴더에 복사해 넣으세요

void foo(int a, double d, int& r) 
{ 
	for (int i = 0; i < a; ++i)
	{
		r = i;
	}
}

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	StopWatch sw(true);	// 1. 생성자에서 현재 시간을 구해서 보관합니다.
						// 2. 생성자 인자로 true 를 전달하면
						//    소멸자에서 다시 시간을 구해서 1에서 구한 시간과의 차이를 출력합니다
						// 3. sw 의 소멸자는 아래 f(...) 가 실행된후 호출됩니다.

	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 3;

	chronometry(foo, 1000000, 3.4, n);  // foo(1000000, 3.4, n);

	std::cout << n << std::endl; 

}
