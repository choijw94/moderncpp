// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 
using namespace std::literals; // ǥ���� �����ϴ� ���ͷ� ���̻簡 
								// �� ������ �ֽ��ϴ�.

void foo(const char* s) { std::cout << "char*\n"; }	
void foo(std::string s) { std::cout << "string\n"; }

int main()
{
	foo("hello");	// char*
	foo("hello"s);  // string.   operator""s(const char*) ȣ��Ǵµ�
					//           ��ȯ Ÿ���� std::string �Դϴ�.
				
}


