#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	int age;
public:
	// 1. retain parameter
	// => 인자로 받은 것을 멤버 데이타에 보관하게 됩니다
	// => 이런 경우를 "retain" 한다고 합니다.
	// => 이런 경우만 move 를 지원하기 위해서 아래 처럼 2개 만들면 됩니다.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }


	// 2. in parameter, not retain
	// => 인자로 받은 것을 멤버에 보관하는 것이 아니라, 함수 안에서 사용만 합니다.
	// => 이런 경우는 move 를 지원할 필요가 전혀 없습니다.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}
};

int main()
{
	std::string n = "kim";
	std::string s = "hello";

	People p;

	p.set_name(n); // 복사
//	p.set_name(std::move(n)); // 이동

	p.print_msg(s);
	p.print_msg(std::move(s)); // 에러는 아니지만 자원을 뺏기지는 않습니다.
								// print_msg 안에서 다른곳에 저장하는 코드가 없습니다.


}








