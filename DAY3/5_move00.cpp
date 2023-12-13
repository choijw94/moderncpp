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
	Point(Point other) : x(other.x), y(other.y) {}

};

int main()
{
	Point p1;			// 1�� ������
	Point p2(1, 2);		// 2�� ������

	Point p3(p2);		// Point(Point) �� ������ �ʿ�
						// => ���� ������ �ʿ�
						// => ����ڰ� ������ �ʾƵ� �����Ϸ��� ����
}




