#include <string>
#include <string_view>

// �Լ� ���ڷ� �б� ���� ���ڿ��� ������

// #1. call by value - worst.. ���� ������� ������
void f1(std::string s) 
{
}

// #2. call by const reference - ���� �θ� ���. �׷���, C++17 ���Ĵ� �ּ��� �ƴ�!!!
void f2(const std::string& s)
{
}

// #3. std::string_view �� call by value �� => best.. C++17 ���Ķ�� �̷��� �ϼ���
void f3(std::string_view sv)
{
}


int main()
{
	std::string s = "to be or not to be";

	f2(s);
	f3(s);

	f2("to be or not to be");
	f3("to be or not to be");
}
