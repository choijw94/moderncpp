#include <iostream>
#include <string>
#include <vector>

// move ����

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1;	// string ���� ������ ȣ��
							// ���� ����� ����
							// ���ڿ� ��ü�� ����

	std::string s4 = std::move(s2);
							// s2 �� ���ڿ� �ڿ��� s4 �� �̵�
							// s2 �� ���̻� ���ڿ� �ڿ��� �����ϴ�.
							// s4 �� s2�� �ڿ��� ���Ҿ� ���� �˴ϴ�.

	std::cout << s1 << std::endl;	// "hello"
	std::cout << s2 << std::endl;	// ""


}

