class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

void foo(Point pt) {}

Point goo() 
{
	Point pt(1, 2);
	return pt;
}

int main()
{
	Point pt(1, 2);
	foo(pt);
}
