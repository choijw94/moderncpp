#include <iostream>
#include <string>

// 자동 생성 규칙.

struct Object
{
	std::string name;
	
	Object(const std::string& n) : name(n) {} // 생성자!

	// 핵심 : 복사 생성자와 이동생성자를 만들지 않았습니다.
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}