#include <iostream>
// 85 page
struct Base
{
	int value = 10; 
};

// #1. 기반 클래스의 멤버와 동일이름의 멤버데이타 추가 가능.
struct Derived : public Base
{	
	int value = 20;
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl;	// 20. 즉, 자신의 멤버 데이타 


	// 기반 클래스의 value 에 접근하려면 캐스팅하면 됩니다.
	// => 아래 2줄의 차이점은!!! 중요합니다. 꼭 기억하세요. C++23에서 중요해 집니다.
	
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
						// => d 를 Base 라고 생각해서 value 에 접근하겠다는 것.
						// => 새로운 객체가 생성되는 것은 아님.

	std::cout << static_cast<Base>(d).value << std::endl; // 10
						// => Base 의 임시객체를 생성하는 것
						// => 즉, 새로운 객체 생성, d 를 복사해서 생성
						// => 생성될때 "복사생성자" 호출

	// 아래 처럼 확인하세요
	static_cast<Base&>(d).value = 30; // ok
	static_cast<Base>(d).value = 30;  // error. 임시객체.value = 30 이므로
}

// 핵심
// 1. 임시객체는 사용자가 의도적으로 만들기도 하고
//    => 주로 함수 인자  draw_line( Point(1,1), Point(5,5))

// 2. 값을 반환하는 함수, 값 캐스팅 등의 코드가
//    => 임시객체를 생성하기도 합니다.

