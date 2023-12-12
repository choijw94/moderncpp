// 1_초기화9. - 63 page
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
	Point p1(1);		// Point(int) 사용
	Point p2(1, 2);		// Point(int, int) 사용

	Point p3({ 1, 2 });	// Point(std::initializer_list<int>) 사용


	Point p4{ 1, 2 };	// <=== 핵심!!
						// 1. Point(std::initializer_list<int>) 사용
						// 2. 1 이 없다면 Point(int, int) 사용


//	Point p5(1, 2, 3);	// error. Point(int, int, int) 생성자가 없다.!

	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list<int>) 사용

	Point p7 = { 1,2,3 }; // ok. Point(std::initializer_list<int>) 는 explicit 아님

	// 핵심 : 생성자 인자로 std::initializer_list<T> 를 사용하면
	// => T 타입의 객체를 몇개라도 전달 가능합니다.
	
	// STL 컨테이너를 생각해 봅시다.
	std::vector<int> v1 = { 1,2,3,4 };
	std::vector<int> v2{ 1,2,3,4 };
			// vector(std::initializer_list<int> e) 가 있기 때문에 가능

	// 핵심 
	// => std::initializer_list 를 만든 이유는 STL 컨테이너를 배열 처럼 초기화
	//    하기 위해 만든것.
}


