// 8_nullptr2
#include <iostream>

void foo(int* p) {}

int main()
{
	int n = 0;

	// �Ʒ� 2���� ������ ������.
	foo(0);	// ok.	  0�� �������� �����ͷ� �Ͻ��� ����ȯ �����մϴ�.
	foo(n);	// error. ���ͷ� 0�� �����ͷ� �Ͻ��� ����ȯ �ǰ�
			//        0���� �ʱ�ȭ�� ���� n�� �����ͷ� �Ͻ��� ����ȯ �ȵ˴ϴ�.
}

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)
{
	f(arg);
}






