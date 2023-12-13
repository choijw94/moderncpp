// 9_�Ϻ�������_���ǻ���
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0; �ް� �Ǹ� f(arg) �� ����
{								// => int ������ arg �� �����ͷ� �Ͻ��� ��ȯ �ȵ�
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
	foo(0); // ok

//	chronometry(foo, 0); // foo(0) �ǵ�����, error
	chronometry(foo, nullptr); // ok..  std::nullptr_t �̹Ƿ� (1���� �ҽ� ����)
}
// �Ϻ��� ���� ����� �ᱹ ���ø� �Դϴ�.
// => ���� ���� �޴� �Լ��� ���ڰ� ������ �� ���, 0 ����ϸ� ������ ���� �Դϴ�.
// => 0 ��� nullptr ����ϼ���..








