// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
public:
	int x, y;

//	Point() {}				
	Point() = default;		
};

int main()
{
	Point p{};  // C++11 ���� �̷� �ʱ�ȭ�� ����( ȭ~���� ���� �˴ϴ�)
				// => ��� ����� 0���� �ʱ�ȭ. ��, ����Ʈ �����ڸ� �����Ϸ��� ������������
				// => ����ڰ� ������ ������ ������ ���� 0���� �ʱ�ȭ �ȵ�

	std::cout << p.x << ", " << p.y << std::endl;
}





