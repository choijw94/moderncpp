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
	// => 단, rvalue 를 받을수 없다
	// => Point ret = foo(); 에서 foo 가 값반환(임시객체, rvalue) 이라면 에러!!
	// Point(Point& other) : x(other.x), y(other.y) {}

	// #3. call by const (lvalue) reference
	// => C++98 시절에 lvalue, rvalue 를 모두 받을수 있는 유일한 방법
	Point(const Point& other) : x(other.x), y(other.y) {}
};

Point foo()	
{
	Point p(1, 2);
	return p;		// 값 반환 이므로 임시객체 입니다.
}

int main()
{
	Point p1;			// 1번 생성자
	Point p2(1, 2);		// 2번 생성자

	Point p3(p2);		// Point(Point) 의 생성자 필요
						// => 복사 생성자 필요
						// => 사용자가 만들지 않아도 컴파일러가 제공
						// => Point p3 = p2;

	Point ret = foo();  // 복사 생성자 인자가 Point& 였다면 에러!
}




