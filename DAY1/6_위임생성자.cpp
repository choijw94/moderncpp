#include <iostream>

// 6_위임생성자 - 24page
class Point
{
public:
	int x, y;
public:

	Point() 
	{
		Point(0, 0); // 생성자 안에서 다른 생성자 호출 ??
					 // => 아닙니다.
					 // => C++98 문법에서 생성자에서 다른 생성자 호출 안됩니다.
					 // => 이 표기법은 "임시객체를 생성" 하는 표기법
	}

	Point(int a, int b) : x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

