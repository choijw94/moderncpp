#include <iostream>

// 6_���ӻ����� - 24page
class Point
{
public:
	int x, y;
public:

	Point() 
	{
		Point(0, 0); // ������ �ȿ��� �ٸ� ������ ȣ�� ??
					 // => �ƴմϴ�.
					 // => C++98 �������� �����ڿ��� �ٸ� ������ ȣ�� �ȵ˴ϴ�.
					 // => �� ǥ����� "�ӽð�ü�� ����" �ϴ� ǥ���
	}

	Point(int a, int b) : x(a), y(b)
	{
		// ������ �ʱ�ȭ �ڵ�
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

