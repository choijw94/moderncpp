// 7_�Ϻ�������1 - 113 page
#include <iostream>

// foo, goo �� �پ��� �Լ��� ����(����ð�)�� �����ϰ� �ʹ�.

void foo(int a)  {}
void goo(int& a) { a = 100; }


// forwarding : ���� ���� ���ڸ� �ٸ� �Լ��� �ٽ� ���� �ϴ� ��
// 
// perfect forwarding(�Ϻ��� ����)
// => �ٸ� �Լ��� ���� �Ҷ�, ��� ��ȭ�� ���� ���� �״�� �����ϴ� ���!



// Ư�� �Լ��� ����(����ð�)�� �����ϴ� �Լ�
template<typename F, typename T>
void chronometry(F f, const T& arg) // �̷��� �ص� �Ϻ��� ������ �ƴմϴ�.!!
{
	// =========> ���⼭ �ð� ������ ����
	f(arg);	   // �Լ��� ȣ��
	// =========> ���⼭ �ٽ� �ð��� ������ ����ð� ���
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10) �� ���� �ð��� ������ �޶�.
	chronometry(goo, n);  // goo(n)  �� ���� �ð��� ������ �޶�.

	std::cout << n << std::endl;
}
