// move 를 배우기 전에 
// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 컴파일러가 만드는 복사 생성자의 모양
	Point(const Point& other) : x(other.x), y(other.y) {}

};

int main()
{
	Point p1;			// 1번 생성자
	Point p2(1, 2);		// 2번 생성자

	Point p3(p2);		// Point(Point) 의 생성자 필요
						// => 복사 생성자 필요
						// => 사용자가 만들지 않아도 컴파일러가 제공
}




