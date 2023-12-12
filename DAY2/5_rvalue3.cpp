#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;

//	n + 5 = 20; // error. "n + 5" 는 rvalue  

	// lvalue, ravlue 를 조사하려면
	// => decltype 의 규칙을 잘생각해 보세요
//	using T = decltype(n + 5);	
				// n+5 가 lvalue 라는 T 는 참조 타입
				//        rvalue 라는 T 는 값 타입

//	using T = decltype(n++);

//	using T = decltype( n );	// n 은 lvalue 지만, 
								// 심볼의 이름만 있으므로 규칙 2가 아닌 규칙1
								// 따라서 참조 타입 아님
	using T = decltype( (n) );	// ()가 추가 되었으면 규칙 1이 아닌 규칙 2 사용

	if (std::is_lvalue_reference_v<T>)
		std::cout << "lvalue" << std::endl;
	else 
		std::cout << "rvalue" << std::endl;
}