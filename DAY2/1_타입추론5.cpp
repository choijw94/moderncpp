#include <iostream>

// ���ڰ� �迭�϶�.. 

// #1. �迭�� ������ ���޹����� T �� �����Ͱ� �˴ϴ�.
template<typename T> void foo(T a)
{
	std::cout << __FUNCSIG__ << std::endl;
}
// �迭�� ������ ������ T �� �����Ͱ� �ƴ� �迭, T=int[3]
template<typename T> void goo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int x[3] = { 1,2,3 };

	// x�� Ÿ�� : int[3]
	foo(x); // ���� T �� int[3] �� �����ϸ�
			// int a[3] = x; �� �˴ϴ�. �迭�� ���簡 �ȵǹǷ� ������ ����!!
			// int* a = x;   �� �����ߴٸ� ok.

	goo(x);	// T �� int[3] �� �����ϸ�
			// "int(&a)[3] = x; �� �˴ϴ�. �迭�� ����Ű�� ������ ���� �ƴ�.
			// �׷��� T �� �����Ͱ� �ƴ� �迭�� ����
}