#include <iostream>
#include <string>

// rule of 0
// => 복사, 이동 아무것도 만들지 않으면 컴파일러가 모두 지원한다.

// => 자원 관리를 직접 하지말고, 자원관리 클래스(STL) 에 의존해라
// char* => std::string
// int*  => std::vector, std::shared_ptr


class Cat
{
	std::string name;
	int   age;
public:
	Cat(const std::string& n, int a) : name(n),  age(a)
	{
	}
};


int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// 객체를 만들때 초기화. 복사 생성자 호출

	c2 = c1;		// 객체를 만든후에 대입. 대입연산자 호출.


	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




