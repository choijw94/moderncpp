// 7_�Ϻ�������1 - 113 page
#include <iostream>

// foo, goo �� �پ��� �Լ��� ����(����ð�)�� �����ϰ� �ʹ�.

void foo(int a)  {}
void goo(int& a) { a = 100; }


// Ư�� �Լ��� ����(����ð�)�� �����ϴ� �Լ�
template<typename F, typename T>
void chronometry(F f, T arg)
{
	// =========> ���⼭ �ð� ������ ����
	f(arg);	   // �Լ��� ȣ��
	// =========> ���⼭ �ٽ� �ð��� ������ ����ð� ���
}

int main()
{
	int n = 10;

	foo(10);

	goo(n);

	std::cout << n << std::endl;
}
