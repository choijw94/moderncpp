#include <string>
#include <string_view>

// 함수 인자로 읽기 전용 문자열을 받을때

// #1. call by value - worst.. 절대 사용하지 마세요
void f1(std::string s) 
{
}

// #2. call by const reference - 가장 널리 사용. 그러나, C++17 이후는 최선이 아님!!!
void f2(const std::string& s)
{
}

// #3. std::string_view 를 call by value 로 => best.. C++17 이후라면 이렇게 하세요
void f3(std::string_view sv)
{
}


int main()
{
	std::string s = "to be or not to be";

	f2(s);
	f3(s);

	f2("to be or not to be");
	f3("to be or not to be");
}
