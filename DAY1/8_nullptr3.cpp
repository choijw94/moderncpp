#include <iostream>

// nullptr 의 정체!!
// => 직접 만들어 봅시다.
// 1. boost 라는 라이브러리에서 실제로 아래 mynullptr_t 클래스로 만들어서 사용.
// 2. C++11 표준을 만들때 boost 의 nullptr 이 채택됨.
// => 단, 표준은 아래와 같은 구조체가 아닌 "nullptr" 자체가 키워드.

void foo(int* p) {}
void goo(char* p) {}

//====================================
struct mynullptr_t
{
	// 변환 연산자 : 객체가 다른 타입으로 암시적 변환이 필요할때 호출되는 함수
//	operator int* () { return 0; }
//	operator char* () { return 0; }

	template<typename T>
	inline operator T* () const { return 0; }
};
mynullptr_t mynullptr;
//====================================

int main()
{
	foo(mynullptr); // mynullptr.operator int*() 라는 멤버 함수 필요

	goo(mynullptr);
}