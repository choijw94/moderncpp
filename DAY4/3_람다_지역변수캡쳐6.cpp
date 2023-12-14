// 3_람다_지역변수캡쳐6
#include <functional>
#include <iostream>

int main()
{
	// #1. 아래 코드의 메모리 구조를 정확히 이해해 보세요
	// => v1, v2, f1, f2 의 메모리 그림.
	int v1 = 0, v2 = 0;

	auto f1 = [v1, v2](int a, int b) mutable { v1 = a; v2 = b; };
	auto f2 = [&v1, &v2](int a, int b) { v1 = a; v2 = b; };

	f1(10, 20);	// f1 객체에 있는 v1, v2 복사본 변경
	std::cout << v1 << ", " << v2 << std::endl; // 0, 0

	f2(10, 20);
	std::cout << v1 << ", " << v2 << std::endl; // 10, 20
	//========================================================
	// 아래 코드를 생각해보세요
	// auto f;  // 이렇게 할수가 없어서
	std::function<void(int, int)> f; // auto 대신 function 으로 했습니다.
	
	{
		int n1 = 0, n2 = 0;

		f = [&n1, &n2](int a, int b) { n1 = a; n2 = b; };

	}	// <== 이순간 n1, n2 는 파괴 됩니다.
		// <== f 객체가 가진 참조(n1, n2) 는 잘못된 참조가 됩니다.
		// <== dangling reference!!

	f(10, 20); // 결국 지역변수 n1, n2 를 변경
	

}