// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };


	// # 1. C++98 시절에 반복자를 얻는 코드
	// => 아래 처럼 반복자의 타입을 직접 사용하면
	// 단점 1. 코드가 복잡해 보이고
	//      2. 컨테이너 변경시 반복자 타입도 변경되어야 합니다.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// # 2. 반복자 타입을 직접 사용하지 말고, auto 사용하세요
	// => 컨테이너 변경시 좌변을 수정할필요 없습니다.
	// => 단 아래 코드는 v 가 배열이라면 error 입니다.
//	auto p1 = v.begin();
//	auto p2 = v.end();


	// # 3. 멤버 함수 begin 보다 일반 함수 begin 이 유연성이 좋습니다.
	// => 아래 처럼 사용하면 v 가 배열이어도 문제 없습니다.
	auto p1 = std::begin(v);
	auto p2 = std::end(v);

}