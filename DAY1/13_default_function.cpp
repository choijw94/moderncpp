// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// # 1. ���� �����ڰ� �ֱ� ������
	//      ���ڰ� ����(����Ʈ������)�� �����Ϸ��� �������� �ʽ��ϴ�.

	// # 2. ���� ���� �����ڸ� ����� 2���� ���
//	Point() {}				// ����ڰ� ���� ����
	Point() = default;		// �����Ϸ����� ��û
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




