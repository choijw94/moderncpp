// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다 표현식이 만드는 클래스의 operator()는 상수 멤버 함수.
	// => 그래서, "v1 = 100" 이 에러
//	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; // error

	// #2. mutable 람다 표현식은 operator()가 상수함수가 아닙니다.
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; // ok

	f1(0); // 이순간 v1 = 100 이 실행되지만, 
		   // 여기서 v1 은 main 의 지역변수가 아니라, f1 객체가 보관하는 복사본 변경(아래 클래스 참고)

	std::cout << v1 << std::endl; // 10

	//==============================================
	// 지역변수 캡쳐의 원리 - 아래 컴파일러가 만드는 클래스를 생각해 보세요

	class CompilerGeneratedName
	{
		// 지역변수를 캡쳐하면 멤버 데이타가 추가됩니다.
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline auto operator()(int a) // const
		{ 
			v1 = 100;	// error. operator() 가 const 함수라면, 멤버 데이타 수정 안되므로
						// operator() 가 const 함수가 아니면 ok. 

			return a + v1 + v2; 
		};
	};

//	auto f1 = CompilerGeneratedName(v1, v2);
}





