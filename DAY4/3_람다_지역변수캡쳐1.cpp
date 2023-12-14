// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다표현식에서 전역변수
	auto f1 = [](int a) { return a + g; }; // ok


	// #2. 람다표현식에서 지역변수 접근
//	auto f2 = [](int a) { return a + v1 + v2; }; // error


	// #3. 람다표현식에서 지역변수 접근하려면 지역변수를 캡쳐해야 합니다
	auto f2 = [v1, v2](int a) { return a + v1 + v2; }; // ok. 


	// #4. 캡쳐된 지역변수 변경
	// => mutable 람다는 가능.
	auto f3 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; // error
	auto f4 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; // ok
}





