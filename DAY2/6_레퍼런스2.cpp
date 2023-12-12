#include <iostream>

// 90 page

// �����̸��� �Լ��� �Ʒ�ó�� 3���� ���·� overloading �����մϴ�.
void foo(int& a)       { std::cout << "int&" << std::endl; }		// 1
void foo(const int& a) { std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)      { std::cout << "int&&" << std::endl; }		// 3

int main()
{
	int n = 10;
	foo(n);		// lvalue �̹Ƿ� 1, 2 ��� �����մϴ�. 
				// �׷���, n �� const �� �ƴϹǷ�
				// (1) �� ȣ��. (1)�� ������ (2)�� ȣ��

	foo(10);	// rvalue �̹Ƿ� 2, 3 ��� ����. 
				// (3) �� ȣ��, (3)�� ������ (2)�� ȣ��.

	// lvalue, rvalue �� ���� �ٸ��� �����Ϸ��� : 1, 3 ó�� 2�� ���弼��
	// lvalue, rvalue �� �Ѱ��� �Լ����� ó��   : 2�� ó�� ���弼��. 

	int& r1 = n;
	foo(r1);	// (1) ȣ��, ������ (2)

	int&& r2 = 10; 
	foo(r2);	// 1�� ȣ��!!

//  int n = 10
//	Point pt(1, 2);

	// #1. Ÿ�԰� value category �� �򰥸��� ������
	// 
	//					Ÿ��					value �Ӽ�
	// n				int					lvalue
	// 10				int					rvalue
	// pt				Point				lvalue
	// Point(1,2)		Point				rvalue
	// r1				int&				lvalue
	// r2				int&&				lvalue
	//--------------------------------------------------
//	Point&& r = Point(1, 1);		
				// Point(1,1) �̶�� �ڵ�� rvalue, ��, �� �ڵ�� ��ȣ�� ���ʿ� �ü�����
				// r �̶�� �ڵ�� lvalue, ��ȣ�� ���ʿ� �ü� �ִ�.
//	r.x = 10;

	// #2. �Լ� ������ �ǹ̸� ��Ȯ�� ���� �ϼ���
	// f1(int&)  : int&  Ÿ���� �ްڴٴ� ���� �ƴ϶� int Ÿ���� lvalue �� �ްڴٴ� ��
	// f1(int&&) : int&& Ÿ���� �ްڴٴ� ���� �ƴ϶� int Ÿ���� rvalue �� �ްڴٴ� ��


	// #3.
	int&& r3 = 10;	// 10 �� rvalue, ������ r3 �� lvalue
					// "named rvalue reference is lvalue" - ���� �˻�

	foo(r3);					 // 1��. r3 Ÿ���� int&&, value �Ӽ� lvalue

	foo(static_cast<int&&>(r3)); // 3��
			// => r3�� Ÿ���� int&& �ε� ???
			// => �ٽ� int&& �� ĳ����???
			// => �ᱹ ���� Ÿ�� �ƴѰ��� ?? �̰� � �ǹ̰� ������ ??
			
	// static_cast<Type>(r3) ���� Type �� && �� �پ� �ִ� ���
	// => "Ÿ�� ĳ����" �� �ƴ� "value �Ӽ��� �����ϴ� ĳ����" �Դϴ�.
	// => cppreference.com ���� "static_cast" ã�� ������


	
}




// ǥ������ "�ϳ��� ��" ���� ��� �ɼ� �ִ� �ڵ� ���� �Դϴ�.

// ǥ������ "Ÿ��" �� "value �Ӽ�(category)" �� �з� �˴ϴ�.
// 
// "�ڵ��� ������ ����� ���� ��" �� Ÿ�԰� value �Ӽ�


