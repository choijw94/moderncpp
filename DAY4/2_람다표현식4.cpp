// 5_람다표현식5
#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	// #1. 모든 람다 표현식은 다른 타입 입니다.
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{}; xxx();

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{}; yyy();

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;


	// #2. 람다표현식으로 초기화된 변수에, 다른 람다표현식 담을수 없습니다.
	auto f3 = [](int a, int b) { return a + b; };

//	f3 = [](int a, int b) { return a + b; }; // error. 타입이 다릅니다.


	// #3. 
	// 아래 코드를 잘 생각해 보세요. sort() 함수가 몇개 생성되었을까요 ?
	std::vector<int> v = { 1,2,3 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

}





