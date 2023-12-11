// string_view1.cpp
#include <string>
#include <string_view>

int main()
{
	std::string s = "to be or not to be";

	// #1. 아래 2줄의 메모리 구조를 정확히 알아야 합니다.
	std::string      ss1 = s;	// s 의 자원(문자열을) ss1이 깊은 복사, s 와 ss1 각각 자신의 자원사용
	std::string_view sv1 = s;   // sv1 이 s의 자원을 빌려서 사용. 읽기만 가능.


	// #2. 아래 2줄의 메모리 구조도 정확히 알아야 합니다.
	
	// 1. 프로그램에서 사용하는 문자열은 일단 "상수 메모리에 놓이게 됩니다."
	// 2. std::string      는 자원 소유
	// 3. std::string_view 자원 소유 안함

	const char* p = "to be or not to be";

	std::string      ss2 = "to be or not to be"; // 힙 메모리를 할당해서 문자열 복사
												 // 즉, ss2 가, 자신의 전용 문자열 사용

	std::string_view sv2 = "to be or not to be";
									// 상수 메모리에 있는 문자열 사용
									// 위 p가 가리키는 곳에 있는 문자열 공유
}
