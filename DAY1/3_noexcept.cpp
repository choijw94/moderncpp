// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept 키워드(C++11)는 2가지 용도로 사용됩니다.
// 1. 표현식이 예외가 있는지 조사 할때
// 2. 함수가 예외가 없음(있음)을 알릴때

void foo() 
{
}
void goo()
{
}

int main()
{
	bool b1 = noexcept(foo());
	bool b2 = noexcept(foo());

	std::cout << b1 << ", " << b2 << std::endl;
}




