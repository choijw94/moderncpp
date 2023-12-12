#include <iostream>

// 인자가 배열일때.. 

// #1. 배열을 값으로 전달받으면 T 는 포인터가 됩니다.
template<typename T> void foo(T a)
{
	std::cout << __FUNCSIG__ << std::endl;
}
// 배열을 참조로 받으면 T 는 포인터가 아닌 배열, T=int[3]
template<typename T> void goo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int x[3] = { 1,2,3 };

	// x의 타입 : int[3]
	foo(x); // 만약 T 를 int[3] 로 결정하면
			// int a[3] = x; 가 됩니다. 배열은 복사가 안되므로 컴파일 에러!!
			// int* a = x;   로 결정했다면 ok.

	goo(x);	// T 를 int[3] 로 결정하면
			// "int(&a)[3] = x; 가 됩니다. 배열을 가리키는 참조는 에러 아님.
			// 그래서 T 는 포인터가 아닌 배열로 결정
}