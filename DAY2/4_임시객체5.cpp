#include <iostream>
// 85 page
struct Base
{
	int value = 10; 
};

// #1. ��� Ŭ������ ����� �����̸��� �������Ÿ �߰� ����.
struct Derived : public Base
{	
	int value = 20;
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl;	// 20. ��, �ڽ��� ��� ����Ÿ 


	// ��� Ŭ������ value �� �����Ϸ��� ĳ�����ϸ� �˴ϴ�.
	// => �Ʒ� 2���� ��������!!! �߿��մϴ�. �� ����ϼ���. C++23���� �߿��� ���ϴ�.
	std::cout << static_cast<Base>(d).value << std::endl; // 10
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
}

