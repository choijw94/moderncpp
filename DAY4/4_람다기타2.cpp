#include <iostream>

int main()
{
	
	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2); // 에러는 아니지만 결과는 6


	// generic lambda 
	// => 람다표현식 인자로 auto 를 사용하는 기술
	// => C++14 부터 지원
	auto f1 = [](auto a, auto b) { return a + b; };

	std::cout << f1(1,   2)   << std::endl; // 3
	std::cout << f1(1.1, 2.1) << std::endl; // 3.3
	std::cout << f1(1.1, 2)   << std::endl; // 3.1
	std::cout << f1(1,   2.1) << std::endl; // 3.1
}