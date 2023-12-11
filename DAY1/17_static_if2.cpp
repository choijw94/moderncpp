// 17_static_if - 51 page

template<typename T> void foo(T a)
{
	// 아래 코드는 에러 일까요 ?
	// 현재 T 는 "int 타입" 입니다.

	// if : 실행시간 제어문
	//      조건문이 컴파일 시간에 false 로 결정되어도
	//      인스턴스화된 함수에는 포함됩니다.
//	if (false)
//		*a = 10;

	// if constexpr :  컴파일 시간 제어문
	//                 조건문이 컴파일 시간에 false 로 결정되면
	//				   인스턴스화된 함수에는 포함 안됨.
	//				   C++17

	if constexpr (false)
		*a = 10;
}

int main()
{
	foo(0); 
}

