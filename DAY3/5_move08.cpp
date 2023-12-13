#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 1. 사용자가 복사 계열 함수 와 이동 계열(이동생성자, 이동 대입 연산자)를 모두 제공하지 않으면
// => 컴파일러가 모두 디폴트 버전 제공
// => 컴파일러가 제공한 복사 생성자 : 모든 멤버를 복사
// => 컴파일러가 제공한 이동 생성자 : 모든 멤버를 이동(std::move 사용) 

// 규칙 2. 사용자가 복사계열(복사생성자)만 제공한다면 
// => 컴파일러는 이동 생성자의 디폴트 버전을 제공하지 않습니다.
// => 이동이 필요한 코드(std::move) 가 있다면 "사용자가 만든 복사 생성자 사용"

// => 컴파일러에게 move 계열의 함수를 요청하려면 "= default" 를 사용하세요

struct Object
{
	std::string name;
	
	Object(const std::string& n) : name(n) {} // 생성자!

	// 핵심 : 복사 생성자와 이동생성자를 만들지 않았습니다.


	// 복사 계열만 만들면
	Object(const Object& obj) : name(obj.name)
	{
		std::cout << "copy\n";
	}

	Object(Object&&) = default;
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;	
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // "obj2"
}