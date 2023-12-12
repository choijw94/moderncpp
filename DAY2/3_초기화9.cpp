// 1_�ʱ�ȭ9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }

	Point(std::initializer_list<int> e) 
	{ 
		std::cout << "initializer_list<int>" << std::endl; 

		auto first = e.begin();
		auto last = e.end();

		for (auto n : e)
		{
			
		}
	}
};

int main()
{
	Point p1(1);		// Point(int) ���
	Point p2(1, 2);		// Point(int, int) ���

	Point p3({ 1, 2 });	// Point(std::initializer_list<int>) ���


	Point p4{ 1, 2 };	// <=== �ٽ�!!
						// 1. Point(std::initializer_list<int>) ���
						// 2. 1 �� ���ٸ� Point(int, int) ���


//	Point p5(1, 2, 3);	// error. Point(int, int, int) �����ڰ� ����.!

	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list<int>) ���

	Point p7 = { 1,2,3 }; // ok. Point(std::initializer_list<int>) �� explicit �ƴ�

	// �ٽ� : ������ ���ڷ� std::initializer_list<T> �� ����ϸ�
	// => T Ÿ���� ��ü�� ��� ���� �����մϴ�.
	
	// STL �����̳ʸ� ������ ���ô�.
	std::vector<int> v1 = { 1,2,3,4 };
	std::vector<int> v2{ 1,2,3,4 };
			// vector(std::initializer_list<int> e) �� �ֱ� ������ ����

	// �ٽ� 
	// => std::initializer_list �� ���� ������ STL �����̳ʸ� �迭 ó�� �ʱ�ȭ
	//    �ϱ� ���� �����.
}


