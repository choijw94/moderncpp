// 1_초기화9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};

int main()
{
	Point p1(1);		// Point(int) 사용
	Point p2(1, 2);		// Point(int, int) 사용

	Point p3({ 1, 2 });	// Point(std::initializer_list<int>) 사용


	Point p4{ 1, 2 };	// <=== 핵심!!
						// 1. Point(std::initializer_list<int>) 사용
						// 2. 1 이 없다면 Point(int, int) 사용


	Point p5(1, 2, 3); 
	Point p6{ 1, 2, 3 }; 
	Point p7 = { 1,2,3 };
}


