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

//  int n = 10
//	Point pt(1, 2);

	// #1. 타입과 value category 를 헷갈리지 마세요
	// 
	//					타입					value 속성
	// n				int					lvalue
	// 10				int					rvalue
	// pt				Point				lvalue
	// Point(1,2)		Point				rvalue
	// r1				int&				lvalue
	// r2				int&&				lvalue
	//--------------------------------------------------
//	Point&& r = Point(1, 1);		
				// Point(1,1) 이라는 코드는 rvalue, 즉, 이 코드는 등호에 왼쪽에 올수없다
				// r 이라는 코드는 lvalue, 등호에 왼쪽에 올수 있다.
//	r.x = 10;

	// #2. 함수 인자의 의미를 정확히 이해 하세요
	// f1(int&)  : int&  타입을 받겠다는 것이 아니라 lvalue 을 받겠다는 것
	// f1(int&&) : int&& 타입을 받겠다는 것이 아니라 rvalue 을 받겠다는 것

	// #3.
	int&& r3 = 10;	// 10 은 rvalue, 하지만 r3 는 lvalue
					// "named rvalue reference is lvalue" - 구글 검색

	foo(r3);					 // 1번
	foo(static_cast<int&&>(r3)); // 3번
}







