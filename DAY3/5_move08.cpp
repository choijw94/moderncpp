#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.

// ��Ģ 1. ����ڰ� ���� �迭 �Լ� �� �̵� �迭(�̵�������, �̵� ���� ������)�� ��� �������� ������
// => �����Ϸ��� ��� ����Ʈ ���� ����
// => �����Ϸ��� ������ ���� ������ : ��� ����� ����
// => �����Ϸ��� ������ �̵� ������ : ��� ����� �̵�(std::move ���) 

// ��Ģ 2. ����ڰ� ����迭(���������)�� �����Ѵٸ� 
// => �����Ϸ��� �̵� �������� ����Ʈ ������ �������� �ʽ��ϴ�.
// => �̵��� �ʿ��� �ڵ�(std::move) �� �ִٸ� "����ڰ� ���� ���� ������ ���"

// => �����Ϸ����� move �迭�� �Լ��� ��û�Ϸ��� "= default" �� ����ϼ���

struct Object
{
	std::string name;
	
	Object(const std::string& n) : name(n) {} // ������!

	// �ٽ� : ���� �����ڿ� �̵������ڸ� ������ �ʾҽ��ϴ�.


	// ���� �迭�� �����
	Object(const Object& obj) : name(obj.name)
	{
		std::cout << "copy\n";
	}

	Object(Object&&) = default;
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;	
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // "obj2"
}