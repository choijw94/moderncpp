// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// # 1. 위에 생성자가 있기 때문에
	//      인자가 없는(디폴트생성자)를 컴파일러가 제공하지 않습니다.

	// # 2. 인자 없는 생성자를 만드는 2가지 방법
//	Point() {}				// 사용자가 직접 구현
	Point() = default;		// 컴파일러에게 요청
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




