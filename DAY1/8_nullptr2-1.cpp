// 8_nullptr2
#include <iostream>

void foo(int* p) {}

// ���ڷ� "�Լ�"�� "����"�� �޾Ƽ�
// => "�Լ�(����)" ���·� ȣ���ϴ� �Լ�
template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)	// int arg = 0; 
{
	f(arg); // int arg ���ٸ� error.
}

int main()
{
	foo(0); // ok
//	forward_parameter(foo, 0);	// foo(0) �� �ǵ� ������ error �Դϴ�.
								// 0 ��ü�� literal �̹Ƿ� �����ͷ� ��ȯ ������
								// forward_parameter �� ������ "int arg = 0"
								// �� �ǹǷ� arg �� �����ͷ� �Ͻ��� ��ȯ �ȵ�.

	forward_parameter(foo, nullptr); // ok

}








