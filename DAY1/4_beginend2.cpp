// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 반복자를 꺼내는 3가지 방법
	// # 1. 멤버 함수 begin 사용(C++98)
	auto p1 = v.begin();

	// # 2. 일반 함수 begin 사용(C++11)
	// => v 가 배열이라도 ok
	auto p2 = std::begin(v);

	// # 3. std::ranges::begin 사용(C++20)
	auto p3 = std::ranges::begin(v);


}