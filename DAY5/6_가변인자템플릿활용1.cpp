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

// �ٽ� : int (int, double) ������ Ÿ�Կ��� ��ȯŸ��(int) �� ������ �ֵ���
//       �κ� Ư��ȭ ������ ������ �մϴ�. �̺κ��� �ٽ�!!
// primary template �� template ���ڴ� �Ѱ� ����
// �Ʒ�ó�� �κ� Ư��ȭ �Ҷ��� template ������ ������ �޶� �˴ϴ�.
template<typename R, typename A1, typename A2> struct result< R(A1, A2) >
{
	using type = R;
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