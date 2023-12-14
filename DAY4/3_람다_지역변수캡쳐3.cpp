// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. capture by value
	// => main 함수의 지역변수 v1, v2 를 f1 객체가 내부적으로 복사본으로 보관하는것
//	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; 


	// #2. capture by reference
	auto f1 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; };

	f1(0); 

	std::cout << v1 << std::endl; // 100



//==============================================

	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a) const
		{
			v1 = 100;	 // 여기서 v1 은 main 함수의 v1을 가리키는 참조이므로
						//  main 함수의 v1이 변경!!
						//  이코드는 v1이 가리키는 곳을 변경하므로
						//  상수멤버 함수라도 변경가능합니다.

			return a + v1 + v2;
		};
	};

	//	auto f1 = CompilerGeneratedName(v1, v2);
}





