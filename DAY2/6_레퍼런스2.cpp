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

//	Point pt(1, 2);

	// Ÿ�԰� value category �� �򰥸��� ������
	// 
	//					Ÿ��					value �Ӽ�
	// n
	// 10
	// pt
	// Point(1,2);
	// r1
	// r2
	//--------------------------------------------------
}







