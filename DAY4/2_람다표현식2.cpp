// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// 람다표현식의 원리!
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	//=======================================================
	// 위 코드를 컴파일러가 아래처럼 변경합니다.
	
	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b) const
		{
			return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName() );

	// 결국 람다 표현식의 최종 결과는 "임시객체" 입니다.
	// lambda expression 에서 "expression(표현식)" 은 하나의 값으로 계산되는 코드!
	// => 함수객체를 임시객체 형태로 생성한것. 
	// => 결국, "클로져" 를 만든것
	// => cppreference.com 의 1번째 화면에서 expression 선택
	//    expression 문서의 중간에서 "lambda exression 선택" 후 1번째 설명 보세요

}





