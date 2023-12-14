// 3_����_��������ĸ��6
#include <functional>
#include <iostream>

int main()
{
	// #1. �Ʒ� �ڵ��� �޸� ������ ��Ȯ�� ������ ������
	// => v1, v2, f1, f2 �� �޸� �׸�.
	int v1 = 0, v2 = 0;

	auto f1 = [v1, v2](int a, int b) mutable { v1 = a; v2 = b; };
	auto f2 = [&v1, &v2](int a, int b) { v1 = a; v2 = b; };

	f1(10, 20);	// f1 ��ü�� �ִ� v1, v2 ���纻 ����
	std::cout << v1 << ", " << v2 << std::endl; // 0, 0

	f2(10, 20);
	std::cout << v1 << ", " << v2 << std::endl; // 10, 20
	//========================================================
	// �Ʒ� �ڵ带 �����غ�����
	// auto f;  // �̷��� �Ҽ��� ���
	std::function<void(int, int)> f; // auto ��� function ���� �߽��ϴ�.
	
	{
		int n1 = 0, n2 = 0;

		f = [&n1, &n2](int a, int b) { n1 = a; n2 = b; };

	}	// <== �̼��� n1, n2 �� �ı� �˴ϴ�.
		// <== f ��ü�� ���� ����(n1, n2) �� �߸��� ������ �˴ϴ�.
		// <== dangling reference!!

	f(10, 20); // �ᱹ �������� n1, n2 �� ����
	

}