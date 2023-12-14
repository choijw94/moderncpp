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


	// #3. 동일한 람다 표현식을 여러번 사용하게 된다면, 
	//     auto 변수에 담아서 사용하는 것이 좋습니다.
	
	std::vector<int> v = { 1,2,3 };

	// 아래 코드를 잘 생각해 보세요. sort() 함수가 몇개 생성되었을까요 ?
	// => 동일한 람다 표현식이라도 다른 타입이므로 "3개의 sort" 생성됩니다.
	// => sort 같은 함수가 "구현이 간단하고 inline 또는 constexpr 이고
	//    컴파일러 최적화 까지 고려했을때는 아래 코드는 오버헤드가 크지 않습니다!
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });


	// 아래 처럼 사용하면 "1개의 sort" 만 생성됩니다.
	auto cmp = [](int a, int b) { return a < b; };

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// < 연산이 필요하다면 람다표현식이 아닌 "std::less" 를 사용해도 됩니다
	std::sort(v.begin(), v.end(), std::less<int>());
	std::sort(v.begin(), v.end(), std::less<int>());
	std::sort(v.begin(), v.end(), std::less<int>());
}





