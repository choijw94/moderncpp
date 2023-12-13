// 8_�Ϻ�������Ȱ��
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector�� ��� �ֱ�. 
	// => �Ʒ� ������ ����� ���� ȭ�� ��� ����� ��Ȯ�� ���� �ϼ���
	
	// #1. ��ü�� ������ �Ŀ� �ֱ�
//	Point pt(1, 2);
//	v.push_back(pt);


	// #2. �ӽð�ü ���·� �����ؼ� �ֱ�
//	v.push_back( Point(1, 2) );


	// #3. {} �ʱ�ȭ ���·� ����
//	v.push_back({ 1,2 }); // #2 �� ������ �ڵ�


	// #4. ��ü�� �������� ����, 
	//     ��ü�� ����� ���� "������ ����"�� ��������!! �ٽ�!!!!
	v.emplace_back(1, 2);
			// => emplace_back �Լ��� ���������� "new Point(1,2)" ó�� ���ۿ� ��ü����


	std::cout << "-----" << std::endl;
}


