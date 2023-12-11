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

	std::chrono::seconds s1(10); // �� �ڵ��
	auto s2 = 10s;               // �� �ڵ�� �����մϴ�.
					// std::chrono::seconds operator""s(unsigned long long)

	std::chrono::seconds s3 = 1h + 30min + 20s;
				
}


