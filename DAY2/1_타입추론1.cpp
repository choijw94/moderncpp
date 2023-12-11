#include <iostream>

// T의 타입조사하는 방법
template<typename T> void foo(T a)
{
	// #1. RTTI 기술 사용
	// => T 가 가진 const, volatile, reference 를 제거한 결과만 나오게 됩니다.
	// => 절대 이렇게 조사하지 마세요
	// => 현재 C++ 의 RTTI 기술이 완전하지 않습니다. C++26 에서 새로운 기술 등장
	// std::cout << typeid(T).name() << std::endl;


	// #2. 컴파일러에 의해 생성된 함수이름 출력
	// __func__            : C++ 표준 매크로, 함수이름만 담고 있다. 인자는 포함안됨. 
	// __FUNCSIG__         : 인자와 반환 타입을 포함한 함수이름. C++ 표준 아님. VS 만 지원
	// __PRETTY_FUNCTION__ : 인자와 반환 타입을 포함한 함수이름. C++ 표준 아님. g++ 만 지원
	
	//std::cout << __func__ << std::endl;
	//std::cout << __FUNCSIG__ << std::endl;


	// #3. godbolt.org 에서 "어셈블리 코드" 를 확인하면 인자의 타입을 확인 가능


}



int main()
{
	// #1. 타입인자를 명시적으로 전달하는 경우
	// => 사용자가 전달한 타입 사용
//	foo<int>(3.4);      // T = int
	foo<const int&>(3); // T = const int&

	
	// #2. 타입인자를 전달하지 않은 경우. 
	// => 함수 인자를 사용해서 T 의 타입을 결정
	foo(10); // T = int 
	foo(3.4);// T = double

}