class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

void foo(Point pt) {}

Point goo() 
{
//	Point pt(1, 2);
//	return pt;

	return { 1,2 };	// C++11 부터 이렇게 반환도 가능합니다.
}

int main()
{
	Point pt(1, 2);
	foo(pt);

	foo({ 1,2 }); // C++11 부터 이렇게 전달 가능합니다.
				  // Point pt = {1, 2}
}
