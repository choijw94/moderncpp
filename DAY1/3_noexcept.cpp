// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept Ű����(C++11)�� 2���� �뵵�� ���˴ϴ�.
// 1. ǥ������ ���ܰ� �ִ��� ���� �Ҷ�
// 2. �Լ��� ���ܰ� ����(����)�� �˸���

void foo() 
{
}
void goo()
{
}

int main()
{
	bool b1 = noexcept(foo());
	bool b2 = noexcept(foo());

	std::cout << b1 << ", " << b2 << std::endl;
}




