#include <iostream>
#include <string>
#include <type_traits>

int main()
{
	std::string s1;

	// 아래 코드에 대해서 생각해 보세요
	s1 = 65;
	std::string s2 = 65;


	std::cout << std::is_convertible_v<int, std::string> << std::endl;
}