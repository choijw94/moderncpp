// std::move()�Ұ�
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	// ���� ������(copy constructor )
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "����" << std::endl;
	}

	// �̵� ������(move constructor)
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}
};


Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;    // c1 �� lvalue, ���� ������ ȣ�� 
	Cat c3 = foo();	// ��ȯ�� ��ü�� �ӽð�ü(rvalue), �̵������� ȣ�� 

	Cat c4 = static_cast<Cat&&>(c2);
					// lvalue �� c2 �� rvalue �� ĳ���� �����Ƿ�
					// �̵������� ȣ��. c2�� �ڿ��� c4�� �̵�.

	Cat c5 = std::move(c3); // �� �Լ��� ���� ������ ���� ���� ĳ���� �Դϴ�.
					// �ᱹ static_cast<Cat&&>(c3) �� ����.
					// C++ â���ڴ� "std::rvalue_cast" ��� �̸��� ���߽��ϴ�.
					 
	// std::move(obj)
	// 1. std::move ��ü�� �ڿ��� �̵��ϴ� �� �ƴմϴ�.	
	// 2. ����, obj �� rvalue �� ĳ�����ϴ� ��Ȱ�� �մϴ�
	// 3. ĳ������ ����� Cat �� ���� �����ڰ� �ƴ�, �̵������ڰ� ȣ��
	// 4. Cat �� �̵������ڿ��� �ڿ��� �̵�. 

	std::string s1 = "AAAAA";
	std::string s2 = std::move(s1);
					// �� �ڵ嵵 �ᱹ std::string �� �̵� �����ڰ� �ڿ��� �̵��ϴ°�
	// ��, move �� Ŭ���� �����ڰ� å������ �մϴ�.!!!
}

// copy ellision
// => ����ȭ�� ���� �ӽð�ü�� ������ ����, ����(�̵�)�������� ȣ���� �����ϴ� ���
// => ���� ����ȭ ����̾��µ�, C++17 ���� ���Ĺ������� ä��

// �׷��� �Ϻ� ������ ����� ����� �޶����� �ֽ��ϴ�.
// => �̰�� g++ �����Ϸ��� ����ؼ� "�� ����� �������� ����" �� �ϸ� �˴ϴ�.
// => visual studio �� �̿ɼ��� �����ϴ�.

// => g++ �ҽ��̸�.cpp -fno-elide-constructors


