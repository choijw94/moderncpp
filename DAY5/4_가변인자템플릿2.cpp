#include <iostream>

// 아래 처럼 만들면 foo 는 
// => "인자를 한개만 받을수 있는 템플릿(틀)"

// template<typename T> void foo(T args) { }


// 아래 코드는 인자 갯수에 상관없이 함수 생성이 가능한 틀(템플릿)
// => 인자를 어떤 형태로 전달해도 함수 생성이 가능
template<typename ... Types> 
void foo(Types ... args) 
{
}

int main()
{	
	foo(1);
	foo(1, 2);	
	foo(1, 2, 3);
	foo(1, 3.4, 'A');
}