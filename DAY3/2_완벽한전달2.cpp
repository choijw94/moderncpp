// 7_�Ϻ�������1 - 113 page
#include <iostream>

// foo, goo �� �پ��� �Լ��� ����(����ð�)�� �����ϰ� �ʹ�.

void foo(int a) {}
void goo(int& a) { a = 100; }


template<typename F>
void chronometry(F f, int arg)
{
	f(arg);	
}

int main()
{
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n); 

	std::cout << n << std::endl;
}
