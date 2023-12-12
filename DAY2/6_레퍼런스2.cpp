#include <iostream>

// 90 page

// 동일이름의 함수를 아래처럼 3가지 형태로 overloading 가능합니다.
void foo(int& a)       { std::cout << "int&" << std::endl; }		// 1
void foo(const int& a) { std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)      { std::cout << "int&&" << std::endl; }		// 3

int main()
{
	int n = 10;
	foo(n);		// lvalue 이므로 1, 2 모두 가능합니다. 
				// 그런데, n 은 const 가 아니므로
				// (1) 을 호출. (1)이 없으면 (2)번 호출

	foo(10);	// rvalue 이므로 2, 3 모두 가능. 
				// (3) 을 호출, (3)이 없으면 (2)번 호출.

	// lvalue, rvalue 에 따라 다르게 동작하려면 : 1, 3 처럼 2개 만드세요
	// lvalue, rvalue 를 한개의 함수에서 처리   : 2번 처럼 만드세요. 

	int& r1 = n;
	foo(r1);	// (1) 호출, 없으면 (2)


	int&& r2 = 10; 
	foo(r2);	// 1번 호출!!

//	Point pt(1, 2);

	// 타입과 value category 를 헷갈리지 마세요
	// 
	//					타입					value 속성
	// n
	// 10
	// pt
	// Point(1,2);
	// r1
	// r2
	//--------------------------------------------------
}







