#include <vector>
#include <string>
#include <string_view> // C++17!!

int main()
{
	// std::string      : �ڿ�(���ڿ��� ����) �մϴ�
	// std::string_view : �ڿ��� �������� �ʰ�, ������ ����մϴ�.
	std::string s = "to be or not to be";
	std::string_view sv = s;


	// �Ʒ� �ڵ带 ������ ������
	auto p1 = std::ranges::begin(std::vector<int>{1, 2, 3});
	auto p2 = std::ranges::begin(std::string_view{s});

	
}