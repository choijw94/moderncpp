// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// 규칙 1. non-const lvalue reference 는 lvalue 만 가리킬수 있다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error


	// 규칙 2. const lvalue reference 는 lvalue, rvalue 를 모두 가리킬수 있다.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(0, 0);	// ok


	// 규칙 3. C++11 에서 추가된 규칙, 
	// => 상수성 없이 rvalue 를 가리키는 reference 문법 추가
	// => "rvalue reference 는 rvalue 만 가리킬수 있다."
	Point&& r5 = pt;			// error
	Point&& r6 = Point(0, 0);	// ok

	// 왜?? 상수성 없이 임시객체를 가리키는 문법이 필요 합니까 ?
	// => move 와 perfect forwarding 을 위해서!(3일차 수요일)


	// 그런, const rvalue reference 는 어떻게 되나요 ?
	// => rvalue 만 가능합니다.
	// => 그런데, 사용할일이 없습니다.( 왜 사용하지 않는가를 이해하면 많을 것을 알게됩니다.)
	const Point&& r7 = pt;			// error
	const Point&& r8 = Point(0, 0);	// ok

}