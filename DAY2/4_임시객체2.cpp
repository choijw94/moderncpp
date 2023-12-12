// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� Ư¡ - 79 page
int main()
{
	Point pt(1, 2);
	
	// #1. �ӽð�ü�� = �� ���ʿ� �ü� ����.(lvalue �� �ɼ� ����, �ӽð�ü�� rvalue)
	pt.x = 10;			// ok 	
	Point(1, 2).x = 10;	// error. 
						

	// #2. �ӽð�ü�� �ּ� �����ڷ� �ּҸ� ���Ҽ� �����ϴ�.
	Point* p1 = &pt;			// ok		
	Point* p2 = &Point(1, 2);	// error.
								// visual studio 2017 ��� ������ ���� �ʴ� ��찡 �ִµ�,
								// ǥ�� ���������� ������ �½��ϴ�.
							
	// #3. �ӽð�ü�� non-const ������ ����ų�� ����.
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error


	// #4. �ӽð�ü�� const ������ ����ų�� �ֽ��ϴ�.
	const Point& r4 = Point(1, 2);	// ok
									// �̼��� �ӽð�ü�� ������ r4 �� �������� ����˴ϴ�.
									// lifetime extension
									// �̸� ���� ��ü�� �̸��� �ο��Ѱ�!

	r4.x = 10; // error. ��ü�� ���� ��ȿ������ r4 �� const & �̹Ƿ� ����� �ȵ�.


	// #5. C++11 ���鶧, ����� ���� �ӽð�ü�� ����Ű�� �;����ϴ�.
	// => move �� perfect forwarding �̶�� ��� ����. 
	// => rvalue reference ���� ����.
	Point&& r5 = Point(1, 2);
	r5.x = 10; // ok
}

// ARM : Annoted Reference Manual
// => C++ â���ڰ� C++ �� �� ������ ���� ������ ö�п� ���ؼ� �����ϴ� å(1990���)





