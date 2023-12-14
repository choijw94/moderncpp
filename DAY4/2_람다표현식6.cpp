// 145 page
#include <iostream>
int main()
{
	// 람다표현식의 정확한 모양
	auto f1 = [](int a, int b) -> int { return a + b; };

	// #1. return 문장이 한개라면 반환 타입 생략 가능
	auto f2 = [](int a, int b) { return a + b; };

	// #2. return 문장이 여러개 라도 같은 타입을 반환하면 반환 타입 생략 가능
	auto f3 = [](int a, int b) { if (a == 0) return b;  return a + b; };

	// #3. return 문장이 여러개이고 다른 타입을 반환하면 
	//	   반드시 return 타입 표기해야 합니다.
	//     아래 코드는 에러. 
	auto f4 = [](double a, int b) { if (a == 0) return b;  return a; }; 

	
}

