#include <iostream>
#include <string>
#include <type_traits>

int main()
{
	std::string s1;

	// �Ʒ� �ڵ忡 ���ؼ� ������ ������
	s1 = 65;
	std::string s2 = 65;


	std::cout << std::is_convertible_v<int, std::string> << std::endl;
}