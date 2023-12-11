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

	// std::ranges::begin 은 안전성을 추가하기위해 만든것
	// => 아래 2줄을 생각해 보세요
	// => 인자가 임시객체입니다.
	auto p4 = std::begin( std::vector<int>{1, 2, 3, 4, 5} );
				// => 컴파일 에러 아닙니다.
				// => 하지만, 임시객체 vector 는 즉시 파괴 되므로
				// => p4 사용시 runtime error

	auto p5 = std::ranges::begin( std::vector<int>{1, 2, 3, 4, 5} );
				// => 컴파일 에러!! 

}