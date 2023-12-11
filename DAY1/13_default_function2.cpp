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

	std::cout << p.x << ", " << p.y << std::endl;
}





