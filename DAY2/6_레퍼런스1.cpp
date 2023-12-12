// 3_���۷���1.cpp - 89 page - ���� �߿�!

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// ��Ģ 1. non-const lvalue reference �� lvalue �� ����ų�� �ִ�.
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error


	// ��Ģ 2. const lvalue reference �� lvalue, rvalue �� ��� ����ų�� �ִ�.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(0, 0);	// ok


	// ��Ģ 3. C++11 ���� �߰��� ��Ģ, 
	// => ����� ���� rvalue �� ����Ű�� reference ���� �߰�
	// => "rvalue reference �� rvalue �� ����ų�� �ִ�."
	Point&& r5 = pt;			// error
	Point&& r6 = Point(0, 0);	// ok

	// ��?? ����� ���� �ӽð�ü�� ����Ű�� ������ �ʿ� �մϱ� ?
	// => move �� perfect forwarding �� ���ؼ�!(3���� ������)


	// �׷�, const rvalue reference �� ��� �ǳ��� ?
	// => rvalue �� �����մϴ�.
	// => �׷���, ��������� �����ϴ�.( �� ������� �ʴ°��� �����ϸ� ���� ���� �˰Ե˴ϴ�.)
	const Point&& r7 = pt;			// error
	const Point&& r8 = Point(0, 0);	// ok

}