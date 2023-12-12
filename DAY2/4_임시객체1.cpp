// 1_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};

int main()
{
//	Point pt(1, 2);		// named object 
						// 수명 : 자신을 선언한 블럭을 벗어 날때 파괴.

//	Point (1, 2);		// 위와 동일한 코드에서 "객체이름" 만 제거
						// unnamed object( temporary, 임시객체)
						// 수명 : {} 이 아닌 문장의 끝


	Point(1, 2), std::cout << "X" << std::endl;


	std::cout << "-------" << std::endl;
}

// 파이썬, Rust 등의 언어도 임시객체 개념 있습니다.
// p1 = Point(1, 2) // p1 이름이 파괴될때 deinit 호출
// Point(1, 2)      // 다음줄로 가기전에  deinit 호출



