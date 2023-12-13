#include <string>
#include <iostream>

int main()
{
	// std::move : 단지 rvalue 로 캐스팅 할 뿐입니다.
	//			   이동생성자가 있는 타입만 효과가 있습니다

	// #1
	std::string s1 = "aaaaaa";
	std::string s2 = std::move(s1);


}