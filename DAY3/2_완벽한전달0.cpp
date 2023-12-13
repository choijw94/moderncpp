#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int&& r = 10;	// 10 은 rvalue
					// r  은 lvalue

	foo(r);	// r의 타입은 int&& 지만, value 속성은 lvalue 이므로
			// foo(int&) 호출.

	foo(static_cast<int&&>(r)); // foo(int&&) 호출
	
	// static_cast<int&&>(r) 는 
	// => 타입캐스팅이 아닌 value 캐스팅(lvalue => rvalue(정확히는 xvalue))

}







