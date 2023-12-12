// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� �Լ� ���� - 81 page
void draw_line(const Point& from, const Point& to) {}

void reset(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
//	Point p1(1, 1);
//	Point p2(5, 5);

//	draw_line(p1, p2);	// ok. ���Լ��� ����ϰ� ���� ���̻� p1, p2 �� �ʿ� ����.
						// ������, p1, p2 �� ��� �ı� ���� �ʰ�, {} ����� �ı�.

	// �Լ� ���ڷθ� ����� ��ü�� "�ӽ� ��ü" �� ����ϴ� ���� �����ϴ�.
	draw_line( Point(1, 1), Point(5, 5) ) ;
	draw_line( {1, 1}, {5, 5} ); // C++11 ���ʹ� �̷��Ե� ����. �� �ڵ�� ����
	//=========================================================

	
	Point pt(1, 1);
	reset(pt); // ok. x, y �� reset �ش޶�.

	reset( Point(1, 1) );	// �ӽð�ü�� reset �ش޶� ? 
							// error. 


	std::cout << "-----" << std::endl;
}

// ����
// ���ڰ� 1���� �����ڸ� explicit �� �ϴ� ���� ���� �ֽ��ϴ�.
// ���ڰ� 2�� �̻��� �����ڵ� explicit �����մϴ�. ���� ��������� �ʽ��ϴ�
// ���ڰ� 0�� �� �����ڵ� explicit �����ϰ�, ���� ����մϴ�.
// 
// Point p1{};
// Point p2 = {}; // explicit ��� error



