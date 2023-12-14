#include <iostream>

class ClosureType
{
	int v1;
	int v2;
public:
	ClosureType(int a, int b) : v1(a), v2(b) {}

	inline int operator()(int a, int b) const { return a + b + v1 + v2; }


	// 아래 함수는 에러 입니다.
	// => static 멤버 함수에서 멤버 데이타 접근 안됩니다.
	// => 그래서 컴파일러가 함수 포인터 변환을 지원하기 위한 아래 함수를 생성할수 없습니다.
	static int helper(int a, int b) { return a + b + v1 + v2; }



	using PF = int(*)(int, int);

	operator PF() { return &ClosureType::helper; }
};


int main()
{
	int v1 = 0, v2 = 0;

	// 캡쳐한 람다 표현식은 함수 포인터로 변환 될수 없습니다.
	// => 아래 코드는 에러!!
	// => 캡쳐 하지 않은 람다 표현식만 함수 포인터 변환 가능합니다.
	//	int(*f)(int, int) = [v1, v2](int a, int b) {return a + b + v1 + v2; }

	int(*f)(int, int) = ClosureType(v1, v2);

	int n = f(1, 2);

	std::cout << n << std::endl; // 3
}












