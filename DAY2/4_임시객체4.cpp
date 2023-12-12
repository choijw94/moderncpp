// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page

void f1(Point  pt) {}	// call by value     : 복사본 객체를 만들어서 받게 된다.
void f2(Point& pt) {}   // call by reference : 복사본 객체를 생성 안함.
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

// 함수의 리턴 타입도 "value", "reference" 에 따라 동작이 다릅니다.

Point foo()		// return by value
{
	return pt;	// pt 를 반환하는 것이 아니라
				// pt 를 복사한 복사본(임시객체)를 반환
}

Point& goo()    // return by reference
{
	return pt;  // 복사본이 아닌 pt 별명 반환
}

int main()
{
	foo().x = 10; // error. 임시객체.x = 10 의 의미

	goo().x = 10; // ok. pt.x = 10
}

// obj1 = obj2;  가 되려면 operator= 가 필요하지 않나요 ?
// => 사용자가 operator= 를 만들지 않으면 컴파일러가 기본 구현제공합니다.
// => 내일 move 에서 아주 자세히 다루게됩니다.






