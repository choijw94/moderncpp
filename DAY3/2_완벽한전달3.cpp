#include <iostream>

// �Ʒ� chronometry �� �� �Ѱ��� ������ �ֽ��ϴ�.
// �Ʒ� hoo �Լ��� ������ ������

void hoo(int&& a) {}


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
	hoo(10); // ok

	chronometry(hoo, 10);	// �Ǿ� �ϴµ� ?? �� �����ϱ�� ?
							// ������ �ذ�å�� �����ҽ�(4.cpp)����!!
}
