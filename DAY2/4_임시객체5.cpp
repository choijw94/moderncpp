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
	std::cout << static_cast<Base>(d).value << std::endl; // 10
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
}

