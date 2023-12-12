// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n1{ 0 };	// direct initialization
	int n2 = { 0 }; // copy   initialization
	int n3;			// default initialization - 지역변수라면 쓰레기값

	int n4{};		// value initialization - {} 안에 값이 없다!
					// => primitive 타입은 0으로 초기화
					// => user define type 은 디폴트 생성자
					// => int 타입은 {} 보다 {0} 사용하세요.

	std::cout << n4 << std::endl; // 0

	Point pt{};		// 모든 멤버를 0으로 초기화
					// => 단, 사용자가 만든 생성자가 없을때만 
	std::cout << pt.x << std::endl;
}


