// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// �Ϲ����� ���ڿ� : '\' �� Ư�� ���ڸ� ǥ���ϱ� ���� ���ڷ� ���
	//				    ���� ���, ����ǥ������ ǥ���Ҷ� ������ ���Դϴ�.

	std::string s1 = "\\\\.\\pipe\\server";


	// Raw String : '\' �� �Ϲ� ���ڷ� ���
	std::string s2 = R"(\\.\pipe\server)";  // �� ���ڿ��� ���� ����

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	// R  : raw string �� ���۵��� �˸��� ǥ��
	// "( : ���ڿ� ����
	// )" : ���ڿ� ����
	std::string s3 = R"(\\.\pipe\server)";

	// ���ڿ� ���̿��� " �� ǥ���ϰ� �ʹ�
	std::string s4 = R"(\\.\pi"pe\ser'ver)";


	// ���ڿ� ���̿��� )" �� ǥ���ϰ� �ʹ�
//	std::string s5 = R"(\\.\pi)"pe\server)"; // error


	// �ذ�å : ���ڿ��� ���۰� ���Ḧ �����ϸ� �˴ϴ�.
	// => " �� ( ���̿� �ƹ� ��ȣ�� ������ �˴ϴ�.
	std::string s6 = R"***(\\.\pi)"pe\server)***";
}