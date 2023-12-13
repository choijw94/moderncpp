#include <iostream>

// 아래 chronometry 는 단 한가지 문제가 있습니다.
// 아래 hoo 함수를 생각해 보세요

void hoo(int&& a) {}


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10);	// 되야 하는데 ?? 왜 에러일까요 ?
							// 이유와 해결책은 다음소스(4.cpp)에서!!
}
