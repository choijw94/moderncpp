// string_view1.cpp
#include <string>
#include <string_view>

int main()
{
	std::string s = "to be or not to be";

	// #1. 아래 2줄의 메모리 구조를 정확히 알아야 합니다.
	std::string      ss1 = s;
	std::string_view sv1 = s;


	// #2. 아래 2줄의 메모리 구조도 정확히 알아야 합니다.
	std::string      ss2 = "to be or not to be";
	std::string_view sv2 = "to be or not to be";
}
