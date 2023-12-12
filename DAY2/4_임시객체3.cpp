// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void draw_line(const Point& from, const Point& to) {}

void init(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
//	Point p1(1, 1);
//	Point p2(5, 5);

//	draw_line(p1, p2);	// ok. 이함수를 사용하고 나면 더이상 p1, p2 는 필요 없다.
						// 하지만, p1, p2 는 즉시 파괴 되지 않고, {} 벗어날때 파괴.

	// 함수 인자로만 사용할 객체는 "임시 객체" 를 사용하는 것이 좋습니다.
	draw_line( Point(1, 1), Point(5, 5) ) ;


	std::cout << "-----" << std::endl;
}





