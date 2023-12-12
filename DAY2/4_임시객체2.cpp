// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt(1, 2);
	
	// #1. 임시객체는 = 의 왼쪽에 올수 없다.(lvalue 가 될수 없다, 임시객체는 rvalue)
	pt.x = 10;			// ok 	
	Point(1, 2).x = 10;	// error. 
						

	// #2. 임시객체는 주소 연산자로 주소를 구할수 없습니다.
	Point* p1 = &pt;			// ok		
	Point* p2 = &Point(1, 2);	// error.
								// visual studio 2017 등에서 에러가 나지 않는 경우가 있는데,
								// 표준 문법에서는 에러가 맞습니다.
							
	// #3. 임시객체는 non-const 참조로 가리킬수 없다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error


	// #4. 임시객체는 const 참조로 가리킬수 있습니다.
	const Point& r4 = Point(1, 2);	// ok
									// 이순간 임시객체의 수명은 r4 의 수명으로 연장됩니다.
									// lifetime extension
									// 이름 없는 객체에 이름을 부여한것!

	r4.x = 10; // error. 객체는 아직 유효하지만 r4 는 const & 이므로 쓰기는 안됨.


	// #5. C++11 만들때, 상수성 없이 임시객체를 가리키고 싶었습니다.
	// => move 와 perfect forwarding 이라는 기술 때문. 
	// => rvalue reference 문법 도입.
	Point&& r5 = Point(1, 2);
	r5.x = 10; // ok
}

// ARM : Annoted Reference Manual
// => C++ 창시자가 C++ 의 각 문법을 만든 이유와 철학에 대해서 설명하는 책(1990년대)





