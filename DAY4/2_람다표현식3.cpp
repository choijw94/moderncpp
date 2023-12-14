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

// C++98
// Point pt = Point(1, 2)
//			  1. �ӽð�ü�� �����ϰ�
//			  2. �ӽð�ü�� pt �� ����(���� ������ ���)
//			  => �׷���, ��κ��� �����Ϸ��� �ӽð�ü�� ����, ��������� ȣ���� ������ �����ϰ�
//               ���ڰ� 2���� �����ڸ� ȣ��� ����ȭ(copy ellision, elide copy constructor )
//			  => �׷���, Point �� ���� �����ڸ� private �� ������ ����
//				 g++ �ҽ�.cpp -std=c++98

// C++11
// Point pt = Point(1, 2)
//			  1. �ӽð�ü�� �����ϰ�
//			  2. �ӽð�ü�� pt �� �̵�(move ������ ���)
//			  => �׷���, ���� ��κ��� �����Ϸ��� ����ȭ �ؼ� ���ڰ� 2���� ������ ȣ��

// C++17
// Point pt = Point(1, 2)
//			  1. ���ڰ� 2���� ������ ȣ��
//            => �ӽð�ü ������ ���縦 �����ϴ� ���� ����ȭ��...!!
//			  => ���� ������ �� �̵������ڰ� ��� private �� �־ ���� �ƴ�.

// auto   f1 = [](int a, int b) { return a + b; }; //
// auto   f1 = ClosureType(); // �ᱹ �����ڸ� 1ȸ ȣ��. �߰� ������� ����

// auto&& f2 = [](int a, int b) { return a + b; }; // ok
// ClosureType* f2 = &ClosureType(); // �ӽð�ü�� �ּҸ� ���Ҽ� ������ ���� ���������� ����
// ���� f2 �� ����ϸ� f2�� ���� �ּҸ� ���ؼ� ��ü�� ����
// ��, ���� ������ �ƴ� �ּҸ� ���ؼ� �����ϹǷ� �ణ�� �������!
