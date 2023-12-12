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
	
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
						// => d �� Base ��� �����ؼ� value �� �����ϰڴٴ� ��.
						// => ���ο� ��ü�� �����Ǵ� ���� �ƴ�.

	std::cout << static_cast<Base>(d).value << std::endl; // 10
						// => Base �� �ӽð�ü�� �����ϴ� ��
						// => ��, ���ο� ��ü ����, d �� �����ؼ� ����
						// => �����ɶ� "���������" ȣ��

	// �Ʒ� ó�� Ȯ���ϼ���
	static_cast<Base&>(d).value = 30; // ok
	static_cast<Base>(d).value = 30;  // error. �ӽð�ü.value = 30 �̹Ƿ�
}

// �ٽ�
// 1. �ӽð�ü�� ����ڰ� �ǵ������� ����⵵ �ϰ�
//    => �ַ� �Լ� ����  draw_line( Point(1,1), Point(5,5))

// 2. ���� ��ȯ�ϴ� �Լ�, �� ĳ���� ���� �ڵ尡
//    => �ӽð�ü�� �����ϱ⵵ �մϴ�.

