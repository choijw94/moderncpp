#include <iostream>

// template 타입 추론 규칙 1. 인자의 타입이 "값(value)" 일때
// => 인자가 가지고 있는 "const, volatile, reference" 의 속성을 제거후에 타입결정
template<typename T> void foo(T a)
{
//	a = 100;
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n);		// T = int 
	foo(c);		// T = int
	foo(r);     // T = int
	foo(cr);    // T = int
}