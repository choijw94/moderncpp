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

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	// �ٽ� : �ӽð�ü(rvalue) �� ��츦 ���� ���� �����ڸ� 
	//        �߰��� ��������(�ڿ��� ���簡 �ƴ� �ڿ��� �̵�)
	//        => ��, ����ȭ�� ������ ���ؼ�
	// 
	// const Cat& : lvalue, rvalue �� ��� ������ ������
	// Cat&& ������ �ִٸ� rvalue �� Cat&& ������ ����ϰ� �ȴ�.

	Cat(Cat&& c) : name(c.name), age(c.age)
	{
		// ���� ���ڷ� ���޵� ��ü(c, �ӽð�ü)�� name �����͸� 0����
		// => �ڿ� ����
		c.name = nullptr;

		// �� �ڵ尡 ����Ƿ��� 
		// => �ӽð�ü�� ����� �ƴ� ������ ������ �־�� �մϴ�.	
	}

};



Cat foo()
{
	Cat c("yaong", 3);
	return c;
}


int main()
{
	Cat c1 = foo(); // �� ���ٿ� ���ؼ� 
					// ������ ������. 
}