#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #3

class People
{
private:
	std::string name;
	int age;
public:
	// 1. retain parameter
	// => ���ڷ� ���� ���� ��� ����Ÿ�� �����ϰ� �˴ϴ�
	// => �̷� ��츦 "retain" �Ѵٰ� �մϴ�.
	// => �̷� ��츸 move �� �����ϱ� ���ؼ� �Ʒ� ó�� 2�� ����� �˴ϴ�.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }


	// 2. in parameter, not retain
	// => ���ڷ� ���� ���� ����� �����ϴ� ���� �ƴ϶�, �Լ� �ȿ��� ��븸 �մϴ�.
	// => �̷� ���� move �� ������ �ʿ䰡 ���� �����ϴ�.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}
};

int main()
{
	std::string n = "kim";
	std::string s = "hello";

	People p;

	p.set_name(n); // ����
//	p.set_name(std::move(n)); // �̵�

	p.print_msg(s);
	p.print_msg(std::move(s)); // ������ �ƴ����� �ڿ��� �������� �ʽ��ϴ�.
								// print_msg �ȿ��� �ٸ����� �����ϴ� �ڵ尡 �����ϴ�.


}








