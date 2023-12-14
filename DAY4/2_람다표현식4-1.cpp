// 5_람다표현식5
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T, typename CMP>
void sort(T first, T last, CMP cmp)
{
}

int main()
{
	std::vector<int> v = { 1,2,3 };

	// 아래 코드를 잘 생각해 보세요. sort() 함수가 몇개 생성되었을까요 ?
	// => 동일한 람다 표현식이라도 다른 타입이므로 "3개의 sort" 생성됩니다.
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	/*
	// 아래 처럼 사용하면 "1개의 sort" 만 생성됩니다.
	auto cmp = [](int a, int b) { return a < b; };

	sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.end(), cmp);

	// < 연산이 필요하다면 람다표현식이 아닌 "std::less" 를 사용해도 됩니다
	sort(v.begin(), v.end(), std::less<int>());
	sort(v.begin(), v.end(), std::less<int>());
	sort(v.begin(), v.end(), std::less<int>());
	*/
}





