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

void reset(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
//	Point p1(1, 1);
//	Point p2(5, 5);

//	draw_line(p1, p2);	// ok. 이함수를 사용하고 나면 더이상 p1, p2 는 필요 없다.
						// 하지만, p1, p2 는 즉시 파괴 되지 않고, {} 벗어날때 파괴.

	// 함수 인자로만 사용할 객체는 "임시 객체" 를 사용하는 것이 좋습니다.
	draw_line( Point(1, 1), Point(5, 5) ) ;
	draw_line( {1, 1}, {5, 5} ); // C++11 부터는 이렇게도 가능. 위 코드와 동일
	//=========================================================

	
	Point pt(1, 1);
	reset(pt); // ok. x, y 를 reset 해달라.

	reset( Point(1, 1) );	// 임시객체를 reset 해달라 ? 
							// error. 


	std::cout << "-----" << std::endl;
}

// 참고
// 인자가 1개인 생성자를 explicit 로 하는 경우는 많이 있습니다.
// 인자가 2개 이상인 생성자도 explicit 가능합니다. 많이 사용하지는 않습니다
// 인자가 0개 인 생성자도 explicit 가능하고, 가끔 사용합니다.
// 
// Point p1{};
// Point p2 = {}; // explicit 라면 error



