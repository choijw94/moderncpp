// 143 
#include <functional>

int main()
{
	// 람다표현식을 담는 방법

	auto f1            = [](int a, int b) { return a + b; }; // auto 변수

	int(*f2)(int, int) = [](int a, int b) { return a + b; }; // 함수포인터
						// => 우변이 임시객체인데.. 어떻게 함수포인터에 담을수 있나요 ?
						// => 오후에 다루게 됩니다.

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; }; // function

	// # 특징 1. auto 변수에 다른 람다를 담을수 없지만, f2, f3 에는 담을수 있습니다.
	// f1 : 컴파일러가 만든 클래스 타입!! - 모든 람다는 다른 타입
	// f2 : 함수 포인터 타입
	// f3 : std::function 타입
//	f1 = [](int a, int b) { return a - b; }; // error
	f2 = [](int a, int b) { return a - b; }; // ok
	f3 = [](int a, int b) { return a - b; }; // ok

	// # 특징 2. 
	f1(1, 2);
	f2(1, 2);
	f3(1, 2);
}