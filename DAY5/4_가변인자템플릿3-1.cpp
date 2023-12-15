#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types>
void foo(Types ... args)
{
	// args : 1, 2, 3
//	goo(args);	// error. pack �̸� ��ü�� �Լ� ���ڷ� ����Ҽ� �����ϴ�.
				//        pack ���� ��Ҹ� , �� �и��ؼ� ������ �մϴ�.


	// #1. pack expansion ������ �˾ƾ� �մϴ�
	// "pack�̸�..."           => E1, E2, E3
	// "pack������ϴ��ڵ�..."  => E1������ϴ��ڵ�, E2������ϴ��ڵ�, E3������ϴ��ڵ�

	goo(args...);		// goo(1, 2, 3)

	goo((++args)...);	// goo(++E1, ++E2, ++E3)

	// �Ʒ� 2���� ������ ������ ������
	goo(hoo(args...));
	goo(hoo(args)...);

}


int main()
{
	foo(1, 2, 3);
}
