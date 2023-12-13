#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// int&& �� T&& �� �� �����ϼ���
	// int&& : rvalue reference
	// T  && : forwarding reference
	
	// #1. �Ʒ� ĳ������ rvalue ĳ�����Դϴ�.
//	static_cast<int&&>(arg);


	// #2. �Ʒ� ĳ������ rvalue ĳ������ �ƴմϴ�.!!
	
	// chronometry �� 2��° ���ڷ�
	
	// rvalue(10) �� (�����ϸ� �����鼭 lvalue �� �� arg �� �ٽ�) rvalue �� ĳ����
	// lvalue(n)  �� (�����ϸ� �ʿ���� ĳ����������         �ٽ�) lvalue �� ĳ����

	// ==> ���� ��������鿡�� �� () �� �����ϰ� �����ؼ� ������� �մϴ�.

//	f(static_cast<T&&>(arg));


	// #3. �� �ڵ�ó�� static_cast ���ص� �Ǵµ�, ��κ� std::forward ���
	f( std::forward<T>(arg) );  // std::forward �� ��ó�� ĳ�����ϴ� C++ ǥ���Լ�
								// T&& �� �ƴ� T �� �����ϸ� �˴ϴ�.
}

int main()
{
	int n = 3;

	chronometry(foo, 10);

	chronometry(goo, n);

}
