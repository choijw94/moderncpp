#include <iostream>
#include <vector>
#include <string>
// #1. move 계열에서는 멤버를 std::move 로 옮겨라!

template<typename T>
class Object
{
	std::string name;
	int age;
	T data;
public:
	Object(const std::string& n) : name(n) {}

	Object(const Object& obj) : name(obj.name) {  }

	// 1. 예외가 없음을 알리기 위한 noexcept
	// f() noexcept			: 예외 없다.
	// f() noexcept(true)	: 예외 없다.
	// f() noexcept(false)  : 예외가 있을수 있다.

	// 2. 예외가 있는지 조사하기 위한 noexcept
	// bool b = noexcept(exp)


	Object(Object&& obj) noexcept (    noexcept(data(std::move(obj.data)))      )
//		: name(obj.name)				// 나쁜 코드 입니다. std::string 의 복사 생성자 호출
		: name( std::move(obj.name) ),	// 좋은 코드. string 의 move 생성자 호출
		  age(obj.age),			// 예외 없음 보장
		  data( std::move(obj.data) )		// ????

	{
	}
};


int main()
{

}

