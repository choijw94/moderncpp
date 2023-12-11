// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// 일반적인 문자열 : '\' 를 특수 문자를 표기하기 위한 문자로 취급
	//				    파일 경로, 정규표현식을 표현할때 복잡해 보입니다.

	std::string s1 = "\\\\.\\pipe\\server";

	// Raw String : '\' 를 일반 문자로 취급
	std::string s2 = R("\\.\pipe\server");  // 이 문자열이 위와 동일

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}