#include <iostream>
#include <string>
#include <vector>

// move 개념

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1;	// string 복사 생성자 호출
							// 깊은 복사로 구현
							// 문자열 자체를 복사

	std::string s4 = std::move(s2);
							// s2 의 문자열 자원을 s4 로 이동
							// s2 는 더이상 문자열 자원이 없습니다.
							// s4 가 s2의 자원을 빼았아 가게 됩니다.

	std::cout << s1 << std::endl;	// "hello"
	std::cout << s2 << std::endl;	// ""


}

