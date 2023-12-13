// 7_완벽한전달1 - 113 page
#include <iostream>

// foo, goo 등 다양한 함수의 성능(수행시간)을 측정하고 싶다.

void foo(int a)  {}
void goo(int& a) { a = 100; }


// 특정 함수의 성능(수행시간)을 측정하는 함수
template<typename F, typename T>
void chronometry(F f, T arg)
{
	// =========> 여기서 시간 측정후 보관
	f(arg);	   // 함수를 호출
	// =========> 여기서 다시 시간을 측정후 수행시간 출력
}

int main()
{
	int n = 10;

	foo(10);

	goo(n);

	std::cout << n << std::endl;
}
