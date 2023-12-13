// move �� ���� ���� 
// ��������� ����� ������ ���ô�.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// �����Ϸ��� ����� ���� �������� ���
//	Point(const Point& other) : x(other.x), y(other.y) {}

	// ���� �����ڸ� ����� ����� ����ڰ� ������� ����ϰ� �˴ϴ�.
	// ���� �������� ��Ȯ�� ����� ������ ���ô�.

	// #1. call by value
	// => Point p3(p2) �� ���� �����ڸ� ȣ���ϰ� �Ǵµ�..  ���� p2 �� ���޵ɶ�
	// => �ٽ�, Point other = p2 �� �ǹǷ� ���� �����ڰ� ������ ȣ��Ǵ� ���
	//    ������ ����!!
//	Point(Point other) : x(other.x), y(other.y) {}

	// #2. call by non-const (lvalue) reference
	// => ���� �ƴ�. 
	// => ��, rvalue �� ������ ����
	// => Point ret = foo(); ���� foo �� ����ȯ(�ӽð�ü, rvalue) �̶�� ����!!
	// Point(Point& other) : x(other.x), y(other.y) {}

	// #3. call by const (lvalue) reference
	// => C++98 ������ lvalue, rvalue �� ��� ������ �ִ� ������ ���
	Point(const Point& other) : x(other.x), y(other.y) {}
};

Point foo()	
{
	Point p(1, 2);
	return p;		// �� ��ȯ �̹Ƿ� �ӽð�ü �Դϴ�.
}

int main()
{
	Point p1;			// 1�� ������
	Point p2(1, 2);		// 2�� ������

	Point p3(p2);		// Point(Point) �� ������ �ʿ�
						// => ���� ������ �ʿ�
						// => ����ڰ� ������ �ʾƵ� �����Ϸ��� ����
						// => Point p3 = p2;

	Point ret = foo();  // ���� ������ ���ڰ� Point& ���ٸ� ����!
}




