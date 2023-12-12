// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// �ӽð�ü�� �Լ� ��ȯ�� -  82 page

void f1(Point  pt) {}	// call by value     : ���纻 ��ü�� ���� �ް� �ȴ�.
void f2(Point& pt) {}   // call by reference : ���纻 ��ü�� ���� ����.
/*
int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/
//===============================================

Point pt(1, 2);

// �Լ��� ���� Ÿ�Ե� "value", "reference" �� ���� ������ �ٸ��ϴ�.

Point foo()		// return by value
{
	return pt;	// pt �� ��ȯ�ϴ� ���� �ƴ϶�
				// pt �� ������ ���纻(�ӽð�ü)�� ��ȯ
}

Point& goo()    // return by reference
{
	return pt;  // ���纻�� �ƴ� pt ���� ��ȯ
}

int main()
{
	foo().x = 10; // error. �ӽð�ü.x = 10 �� �ǹ�

	goo().x = 10; // ok. pt.x = 10
}

// obj1 = obj2;  �� �Ƿ��� operator= �� �ʿ����� �ʳ��� ?
// => ����ڰ� operator= �� ������ ������ �����Ϸ��� �⺻ ���������մϴ�.
// => ���� move ���� ���� �ڼ��� �ٷ�Ե˴ϴ�.






