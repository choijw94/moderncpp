// 3_람다_지역변수캡쳐6
#include <functional>
#include <iostream>

int main()
{
	// #1. 아래 코드의 메모리 구조를 정확히 이해해 보세요
	int v1 = 0, v2 = 0;

	auto f1 = [v1, v2](int a, int b) mutable { v1 = a; v2 = b; };
	auto f2 = [&v1, &v2](int a, int b) { v1 = a; v2 = b; };

	f1(10, 20);
	std::cout << v1 << ", " << v2 << std::endl;

	f2(10, 20);
	std::cout << v1 << ", " << v2 << std::endl;

}