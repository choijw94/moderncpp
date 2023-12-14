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
	int n2 = add.operator()(1, 2); // ok..
}

