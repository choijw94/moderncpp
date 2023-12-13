// move 를 배우기 전에 
// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 컴파일러가 만드는 복사 생성자의 모양
//	Point(const Point& other) : x(other.x), y(other.y) {}

	// 복사 생성자를 사용자 만들면 사용자가 만든것을 사용하게 됩니다.
	// 복사 생성자의 정확한 모양을 생각해 봅시다.

	// #1. call by value
	// => Point p3(p2) 가 복사 생성자를 호출하게 되는데..  인자 p2 가 전달될때
	// => 다시, Point other = p2 가 되므로 복사 생성자가 무한히 호출되는 모양
	//    컴파일 에러!!
//	Point(Point other) : x(other.x), y(other.y) {}

	// #2. call by non-const (lvalue) reference
	// => 에러 아님. 
	Point(Point& other) : x(other.x), y(other.y) {}
};

int main()
{
	Point p1;			// 1번 생성자
	Point p2(1, 2);		// 2번 생성자

	Point p3(p2);		// Point(Point) 의 생성자 필요
						// => 복사 생성자 필요
						// => 사용자가 만들지 않아도 컴파일러가 제공
						// => Point p3 = p2;
}




