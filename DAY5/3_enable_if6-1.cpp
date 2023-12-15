#include <iostream>
#include <string>
#include <type_traits>

int main()
{
	std::string s1;

	// 아래 코드에 대해서 생각해 보세요
	s1 = 65;				// ok. error 아님!
//	std::string s2 = 65;	// error. 


	std::cout << std::is_convertible_v<int, std::string> << std::endl;
								// false
								// int 로 string 을 만들수는 없다는 의미
}