#include <iostream>

// Ÿ�� : ���𹮿��� "�̸�"�� �����ϸ� Ÿ�Ը� ���� �˴ϴ�.
// int n    => �̸��� n, Ÿ�� int
// int x[3] => �̸��� x, Ÿ�� int[3]


// f Ÿ�� : int (int, double)
int f(int a, double b) { return 0; }

// �Լ� Ÿ�Կ��� "��ȯŸ��" �� ������ �ִ� traits �����

// primary template
template<typename T> struct result
{
	using type = T;
};


template<typename T> void foo(T& a) 
{
	// T : int (int, double)
	typename result<T>::type n;  // int

	cout << typeid(n).name() << endl; 
}

int main()
{
	foo(f);
}