// 12_delete_function 37 page

class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// ������, �Ҹ���, ���������,���Կ�����, �̵�������, �̵� ���Կ�����
	// => special member function
	// => ����ڰ� ������ ������ �����Ϸ��� ����Ʈ ������ ����
	// => �ʿ� ���ٸ� "����" �ϸ� �����Ϸ��� �������� �ʽ��ϴ�.

	Point(const Point&) = delete;
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2);	// �����Ϸ��� ������ִ� ��������� ���
					// �����ߴٸ� �����Ϸ��� �������ϹǷ� ����!
}