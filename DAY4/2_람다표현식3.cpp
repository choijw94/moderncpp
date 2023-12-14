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


	// #2. ������ ������ ��� ������ - f2 �Ѱ� ����
	// 
	//     ������ �ƴ� �ڵ��� �ּ��� �ڵ带 ������ - f1 �� �ּ�!!!
	// 
	// �ٽ� : ����ǥ������ ���� ����� "�ӽð�ü(rvalue)" �̴�.

	auto  f1       = [](int a, int b) { return a + b; }; // ok
	auto& f2       = [](int a, int b) { return a + b; }; // error.
								// => �ӽð�ü�� lvalue reference �� ����ų�� ����

	const auto& f3 = [](int a, int b) { return a + b; }; // ok	
	auto&& f4      = [](int a, int b) { return a + b; }; // ok
					// auto&& �� "forwarding reference" �ε�.
					// �캯�� rvalue �̹Ƿ� auto : �� Ÿ��, auto&& ��  Ÿ��&&(rvalue reference)
}

// ���� : Point pt = Point(1, 2) �����ؼ� ������ ���ô�.
