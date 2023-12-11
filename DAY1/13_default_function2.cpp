// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
public:
	int x, y;

//	Point() {}				
	Point() = default;		
};

int main()
{
	Point p{};  // C++11 부터 이런 초기화도 가능( 화~수에 배우게 됩니다)
				// => 모든 멤버를 0으로 초기화. 단, 디폴트 생성자를 컴파일러가 제공했을때만
				// => 사용자가 생성자 구현을 제공한 경우는 0으로 초기화 안됨

	std::cout << p.x << ", " << p.y << std::endl;
}





