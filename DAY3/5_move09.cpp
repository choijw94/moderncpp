#include <iostream>
#include <string>

// rule of 0
// => ����, �̵� �ƹ��͵� ������ ������ �����Ϸ��� ��� �����Ѵ�.

// => �ڿ� ������ ���� ��������, �ڿ����� Ŭ����(STL) �� �����ض�
// char* => std::string
// int*  => std::vector, std::shared_ptr


class Cat
{
	std::string name;
	int   age;
public:
	Cat(const std::string& n, int a) : name(n),  age(a)
	{
	}
};


int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// ��ü�� ���鶧 �ʱ�ȭ. ���� ������ ȣ��

	c2 = c1;		// ��ü�� �����Ŀ� ����. ���Կ����� ȣ��.


	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




