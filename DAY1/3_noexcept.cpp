// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept 키워드(C++11)는 2가지 용도로 사용됩니다.
// 1. 표현식이 예외가 있는지 조사 할때
//	  => bool b = noexcept( expression )
//    => 함수의 구현 자체를 조사하는 것이 아니라,
//       함수의 선언에 noexcept 가 표기되어 있는지 확인하는 것
// 
// 2. 함수가 예외가 없음(있음)을 알릴때

void foo()			// 예외 가능성이 있는 함수
{
}
void goo() noexcept	// 예외 가능성이 없는 함수
{
}

int main()
{
	bool b1 = noexcept( foo() ); 
	bool b2 = noexcept( goo() );

	std::cout << b1 << ", " << b2 << std::endl;
}
// 왜?? 예외가 없다고 알려야 하나요 ??
// => 지금은 noexcept 키워드만 알아두세요
// => 내일 move 배울때 활용됩니다.




