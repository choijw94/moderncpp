// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3); // 1. foo(int) 사용 - exactly matching
			// 2. foo(T) - template 을 사용해서 foo(int) 생성
			// 3. ...
			
	// 위 처럼 동일이름의 함수가 여러개 있을때, 
	// 함수찾는 규칙을 "overloading resolution" 이라고 합니다.
}