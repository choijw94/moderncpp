// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 
using namespace std::literals; // 표준이 제공하는 리터럴 접미사가 
								// 이 공간에 있습니다.

void foo(const char* s) { std::cout << "char*\n"; }	
void foo(std::string s) { std::cout << "string\n"; }

int main()
{
	foo("hello");	// char*
	foo("hello"s);  // string.   operator""s(const char*) 호출되는데
					//           반환 타입이 std::string 입니다.

	std::chrono::seconds s1(10); // 이 코드는
	auto s2 = 10s;               // 이 코드와 동일합니다.
					// std::chrono::seconds operator""s(unsigned long long)

	std::chrono::seconds s3 = 1h + 30min + 20s;
				
}


