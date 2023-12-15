#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

/*
template<typename T>
int foo(T a) 
{ 
	typename T::type n;	 // SFINAE 가 적용될까요 ?
						 // 아니면 에러일까요 ?
						// => 에러 입니다.
	return 0; 
}
*/

// SFINAE 는 "함수 signature" 에서만 가능합니다
// 1. return type
// 2. 함수 인자
// 3. 템플릿 인자

// 1. 아래 코드는 T=int 라는 "return type" 모양이 실패 합니다. - SFINAE 적용
template<typename T>
typename T::type foo(T a) { return 0; }

// 2. 함수 인자 실패
template<typename T>
int foo(T a, typename T::type b = 0) { return 0; }

// 3. 템플릿 인자 실패
template<typename T, typename T2 = typename T::type >
int foo(T a) { return 0; }

int main()
{
	foo(3);
}