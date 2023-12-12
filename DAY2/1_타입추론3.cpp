#include <iostream>

// ��Ģ 2. ������ Ÿ���� "reference(T& a)" �϶�
// => ���ڰ� ���� reference �Ӽ��� �����ϰ� Ÿ�� ����

template<typename T> void foo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  //	T = int,		a = int& 
	foo(c);  // T = const int	a = const int&
	foo(r);  // T = int			a = int&
	foo(cr); // T = const int	a = const int&
}