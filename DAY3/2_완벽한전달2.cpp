// 7_완벽한전달1 - 113 page
#include <iostream>

// foo, goo 등 다양한 함수의 성능(수행시간)을 측정하고 싶다.

void foo(int a) {}
void goo(int& a) { a = 100; }

// 완벽한 전달을 하려면
// 1. 인자의 복사본을 만들면 안된다. call by reference 사용!
// 2. lvalue, rvalue 를 모두 받아야 한다.
// 3. 상수성이 추가되어도 안된다.

// ==> int&, int&& 버전을 따로 제공해야 한다.

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
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n); 

	std::cout << n << std::endl;
}
