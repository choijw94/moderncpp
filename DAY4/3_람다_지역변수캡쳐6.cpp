// 3_����_��������ĸ��6
#include <functional>
#include <iostream>

int main()
{
	// #1. �Ʒ� �ڵ��� �޸� ������ ��Ȯ�� ������ ������
	int v1 = 0, v2 = 0;

	auto f1 = [v1, v2](int a, int b) mutable { v1 = a; v2 = b; };
	auto f2 = [&v1, &v2](int a, int b) { v1 = a; v2 = b; };

	f1(10, 20);
	std::cout << v1 << ", " << v2 << std::endl;

	f2(10, 20);
	std::cout << v1 << ", " << v2 << std::endl;

}