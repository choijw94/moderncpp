#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	printv(args...);	// error. printv(1, 2, 3) 의 의미인데, 
						//		  printv() 의 인자는 한개

//	printv(args)...;	// printv(1), printv(2), printv(3) 의도 이지만
						// error. 
						// 이 위치에서는 pack expansion 이 될수 없습니다.

	// #1. pack expansion 은 아래의 위치에서만 가능합니다.
	// 1. 함수 호출의 () 안			: goo(args...)
	// 2. 템플릿 인자의 <> 안			: std::tuple<Types...>
	// 3. {} 초기화 를 사용하는 구문. : int x[] = {args...};


	// args 의 모든 요소를 printv 에 보내려면
	// => 아래 방법은 C++11 처음 나왔을때 사용했던 방법입니다.
	// => 지금은 더좋은 방법 있습니다.(fold expression 등)
	int x[] = { 0, (printv(args), 0)... }; 
				// { 0, (printv(1), 0), (printv(2), 0), (printv(3), 0) }
}


int main()
{
	foo(1, 2, 3);
	foo();
}

