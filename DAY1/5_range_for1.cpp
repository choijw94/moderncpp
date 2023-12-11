// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>
#include <ranges>
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 문
	for (int i = 0; i < v.size(); i++)
	{
	}

	// C++11 부터 새로운 for 문 제공 - range for 문
	// 파이썬 : for e in v
	// C#     : for var e in v
	for (auto e : v)
	{
	}

	// 전체가 아닌 일부만 할수 없나요 ?
	// 2칸씩 이동 가능한가요 ?
	// 거꾸로 할수 없나요 ?
	// => 모두 C++20 부터 가능. 그전에는 안됨.
	for (auto e : std::views::reverse(v) )
	{
		std::cout << e << ", ";
	}
}















