#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// 핵심 정리
// => 완벽한 전달(perfect forwarding) 기술을 사용하려면

// 1. 인자를 받을때 "T&&(forwarding reference)" 로 받으세요
// 2. 받은 인자를 다른 함수에 보낼때 "std::forward<T>(arg)" 로 묶어서 보내세요

// 참고
// std::forward 는 인자가 rvalue 일 때 만을 위해서 필요 합니다.
//                       lvalue 일때는 없어도 되긴 합니다.
// 하지만 모든 경우를 고려해야 하므로 반드시 "std::forward" 사용하세요. 

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f( std::forward<T>(arg) );  
}


int main()
{
	int n = 3;

	chronometry(foo, 10);

	chronometry(goo, n);

}
