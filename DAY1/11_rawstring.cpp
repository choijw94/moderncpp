// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// 일반적인 문자열 : '\' 를 특수 문자를 표기하기 위한 문자로 취급
	//				    파일 경로, 정규표현식을 표현할때 복잡해 보입니다.

	std::string s1 = "\\\\.\\pipe\\server";


	// Raw String : '\' 를 일반 문자로 취급
	std::string s2 = R"(\\.\pipe\server)";  // 이 문자열이 위와 동일

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	// R  : raw string 이 시작됨을 알리는 표시
	// "( : 문자열 시작
	// )" : 문자열 종료
	std::string s3 = R"(\\.\pipe\server)";

	// 문자열 사이에서 " 를 표기하고 싶다
	std::string s4 = R"(\\.\pi"pe\ser'ver)";


	// 문자열 사이에서 )" 를 표기하고 싶다
//	std::string s5 = R"(\\.\pi)"pe\server)"; // error


	// 해결책 : 문자열의 시작과 종료를 변경하면 됩니다.
	// => " 와 ( 사이에 아무 기호나 넣으면 됩니다.
	std::string s6 = R"***(\\.\pi)"pe\server)***";
}