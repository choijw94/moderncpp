#include <iostream>

// auto �� ���� ǥ����

int main()
{
//	int foo() {} // �Լ� �ȿ� �Լ�, local function, nested function �̶�� �մϴ�

	// #1. ����ǥ������ auto ������ ��Ƽ� �Լ� ó�� ��밡���մϴ�.
	// => �Ϻ� ���(C#��)�� �Լ� �ȿ� �Լ��� ����� �ֽ��ϴ�.
	// => C++ �� �Լ� �ȿ� �Լ��� ����� ���µ�
	//    �Ʒ� ó�� ����� �ᱹ, local function �� ����Ͱ� �����մϴ�.

	auto add = [](int a, int b) { return a + b; };
				// class ClosureType{ operator()(){} }; ClosureType();

	int n1 = add(1, 2);
	int n2 = add.operator()(1, 2);	// ok.. �ᱹ �Լ� ��ü�̹Ƿ� 
									// �̷��� ����ص� �˴ϴ�


	// #2. ������ ������ ��� ������
	//     ������ �ƴ� �ڵ��� �ּ��� �ڵ带 ������
	auto  f1       = [](int a, int b) { return a + b; };
	auto& f2       = [](int a, int b) { return a + b; };
	const auto& f3 = [](int a, int b) { return a + b; };
	auto&& f4      = [](int a, int b) { return a + b; };
}

