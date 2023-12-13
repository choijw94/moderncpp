// 8_�Ϻ�������Ȱ��
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point(int, int)" << std::endl;	}
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

// main					emplace_back						Point(int a, int b)
// 1, 2 ================> ���޹��� ���ڷ� Point ��ü����
//						  ��, new Point(1, 2) =================> 

// emplace_back : ���� ���� 1, 2 �� Point �� �����ڷ� �ٽ� ����.. �մϴ�.
//				  ���� ���� ���ڸ� ��� ���浵 ���� �����ڿ� ������ �մϴ�
//				  "�Ϻ��� ����" ����� ������ ����� �����ϴ�.

// �뷫 emplace_back �� �Ʒ� ���°� �ǰ� �˴ϴ�.
/*
template<typename T> 
decltype(auto) emplace_back(T&& ... args)
{
	new Point(std::forward<T>(args)...);
}
*/

// STL �����̳� ����
// #1. primitive Ÿ���� �����ϴ� �����̳� ( std::vector<int> v) �� ���
// => v.push_back(1)    <== �̷��� �ϼ��� (�������� �Ʒ� ���� �����ϴ�.)
// => v.emplace_back(1) <== �̷��� �ص� �˴ϴ�.


// #2. user define type �����͸� ����(std::vector<Point*> v)
// => v.push_back( new Point ) <== ����, push_back ����ϼ���

// #3. user define type �� value �� ���� �Ѵٸ� (std::vector<Point> v)
// => v.push_back( Point(1,2))  ���ٴ� 
// => v.emplace_back( 1, 2)     �� �ξ� �����ϴ�.  �ǵ��� �̷��� �ϼ���

// ��, ��ü�� ����ϴٰ� �ִ´ٸ� push_back, emplace_back ����..
// Point pt(1,2); // �����..
// pt �� ����ϴٰ�..
// v.push_back(pt);    // �̷��� �ϰų�
// v.emplace_back(pt); // �̷��� �ϰų� ����.
