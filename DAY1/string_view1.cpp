// string_view1.cpp
#include <string>
#include <string_view>

int main()
{
	std::string s = "to be or not to be";

	// #1. �Ʒ� 2���� �޸� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	std::string      ss1 = s;	// s �� �ڿ�(���ڿ���) ss1�� ���� ����, s �� ss1 ���� �ڽ��� �ڿ����
	std::string_view sv1 = s;   // sv1 �� s�� �ڿ��� ������ ���. �б⸸ ����.


	// #2. �Ʒ� 2���� �޸� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	
	// 1. ���α׷����� ����ϴ� ���ڿ��� �ϴ� "��� �޸𸮿� ���̰� �˴ϴ�."
	// 2. std::string      �� �ڿ� ����
	// 3. std::string_view �ڿ� ���� ����

	const char* p = "to be or not to be";

	std::string      ss2 = "to be or not to be"; // �� �޸𸮸� �Ҵ��ؼ� ���ڿ� ����
												 // ��, ss2 ��, �ڽ��� ���� ���ڿ� ���

	std::string_view sv2 = "to be or not to be";
									// ��� �޸𸮿� �ִ� ���ڿ� ���
									// �� p�� ����Ű�� ���� �ִ� ���ڿ� ����
}
