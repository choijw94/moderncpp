// string_view1.cpp
#include <string>
#include <string_view>

int main()
{
	std::string s = "to be or not to be";

	// #1. �Ʒ� 2���� �޸� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	std::string      ss1 = s;
	std::string_view sv1 = s;


	// #2. �Ʒ� 2���� �޸� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	std::string      ss2 = "to be or not to be";
	std::string_view sv2 = "to be or not to be";
}
