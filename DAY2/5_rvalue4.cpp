#include <iostream>
#include <type_traits>

#define VALUE_CATEGORY( ... )										\
	if (std::is_lvalue_reference_v< decltype( ( __VA_ARGS__ ) ) >)	\
		std::cout << "lvalue" << std::endl;							\
	else                                                            \
		std::cout << "rvalue" << std::endl;

int main()
{
	int n = 10;

	VALUE_CATEGORY(n);		// l
	VALUE_CATEGORY(n+1);	// r
	VALUE_CATEGORY(n = 10);	// l
	VALUE_CATEGORY(++n);	// l
	VALUE_CATEGORY(n--);	// r
	VALUE_CATEGORY(10);		// r

	VALUE_CATEGORY("hello"); // ?? lvalue ? rvalue
							// 놀랍게도 lvalue 입니다.
							// 정수, 실수 리터럴 : rvalue	
							// 문자열 리터럴     : lvalue 

	"hello"[0] = 'x';	// error. rvalue 라서 에러가 아니라
						// const 라서 에러 입니다.
}