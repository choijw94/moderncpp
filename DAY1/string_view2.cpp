#include <string>
#include <string_view>

// �Լ� ���ڷ� �б� ���� ���ڿ��� ������

// #1. call by value - worst.. ���� ������� ������
void f1(std::string s) 
{
}

// #2. call by const reference - ���� �θ� ���. 
// �׷���, C++17 ���Ĵ� �ּ��� �ƴ�!!!
void f2(const std::string& s)
{
}


// #3. std::string_view �� call by value �� => best.. 
// C++17 ���Ķ�� �̷��� �ϼ���
void f3(std::string_view sv)
{
}


int main()
{
	std::string s = "to be or not to be";


	f2(s);
	f3(s);

	// �ٽ��� �� �ڵ尡 �ƴ϶�..
	// �Ʒ� �ڵ��϶��� �޸� ������ �˾ƾ� �մϴ�.

	f2("to be or not to be");
				// => ���ڰ� std::string& �̹Ƿ� �� ���ڿ��� ������
				// => std::string �� �ӽð�ü ���� - �� ������ ������尡 Ů�ϴ�.(���ڿ���ü�� ���� ����)
				// => �ӽð�ü�� �Լ��� ����!!!

	f3("to be or not to be");
				// => sv ��ü�� ��� �޸𸮿� ���� ���ڿ��� ���� ����Ű�Ե�.
				// => ������尡 ���� ����.
}
