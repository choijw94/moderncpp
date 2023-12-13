#include <iostream>
#include <vector>
#include <string>
// #1. move 계열에서는 멤버를 std::move 로 옮겨라!

class Object
{
	std::string name;
public:
	Object(const std::string& n) : name(n) {}

	Object(const Object& obj) : name(obj.name) {  }

	Object(Object&& obj) noexcept 
//		: name(obj.name)				// 나쁜 코드 입니다. std::string 의 복사 생성자 호출
		: name( std::move(obj.name) )	// 좋은 코드. string 의 move 생성자 호출
	{
	}
};


int main()
{

}

