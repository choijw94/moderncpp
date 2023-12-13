#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// int&& 와 T&& 를 잘 구별하세요
	// int&& : rvalue reference
	// T  && : forwarding reference
	
	// #1. 아래 캐스팅은 rvalue 캐스팅입니다.
//	static_cast<int&&>(arg);


	// #2. 아래 캐스팅은 rvalue 캐스팅이 아닙니다.!!
	
	// chronometry 의 2번째 인자로
	
	// rvalue(10) 을 (전달하면 받으면서 lvalue 가 된 arg 를 다시) rvalue 로 캐스팅
	// lvalue(n)  를 (전달하면 필요없는 캐스팅이지만         다시) lvalue 로 캐스팅

	// ==> 많은 기술문서들에서 위 () 를 제외하고 설명해서 어려워들 합니다.

	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 3;

	chronometry(foo, 10);

	chronometry(goo, n);

}
