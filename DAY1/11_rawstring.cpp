// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// �Ϲ����� ���ڿ� : '\' �� Ư�� ���ڸ� ǥ���ϱ� ���� ���ڷ� ���
	//				    ���� ���, ����ǥ������ ǥ���Ҷ� ������ ���Դϴ�.

	std::string s1 = "\\\\.\\pipe\\server";

	// Raw String : '\' �� �Ϲ� ���ڷ� ���
	std::string s2 = R("\\.\pipe\server");  // �� ���ڿ��� ���� ����

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}