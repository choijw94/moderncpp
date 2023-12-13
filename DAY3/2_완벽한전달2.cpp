// 7_�Ϻ�������1 - 113 page
#include <iostream>

// foo, goo �� �پ��� �Լ��� ����(����ð�)�� �����ϰ� �ʹ�.

void foo(int a) {}
void goo(int& a) { a = 100; }

// �Ϻ��� ������ �Ϸ���
// 1. ������ ���纻�� ����� �ȵȴ�. call by reference ���!
// 2. lvalue, rvalue �� ��� �޾ƾ� �Ѵ�.
// 3. ������� �߰��Ǿ �ȵȴ�.

// ==> int&, int&& ������ ���� �����ؾ� �Ѵ�.

template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);	
}

template<typename F>
void chronometry(F f, int&& arg)
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
