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

}





