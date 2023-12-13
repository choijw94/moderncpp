#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

/*
template<typename F>
void chronometry(F f, int& arg)
{
//	f(arg);	// A
	f(static_cast<int&>(arg));	// B
								// �ʿ���� ĳ����������, �־ ������ �ƴϰ�
								// �������ϵ� �����ϴ�.(������ �ð��� ���� �˴ϴ�.)
								// static_cast : �����Ϸ��� �ϴ� ĳ����!
}
template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

// �ᱹ int&, int&& ������ �ʿ��ϰ�, int �Ӿƴ϶� �ٸ� Ÿ�Ե� �����ؾ� �մϴ�.
// T&& �� ����ϸ� �� 2���� �ڵ������Ҽ� �ֽ��ϴ�.(int �� �ƴ϶� ��� Ÿ�Կ� ���ؼ�)
// �׷���, ���ø����� �Լ��� �ڵ������Ϸ��� �Լ� ������ �����ؾ� �մϴ�.
// (A �ڵ���, B �ڵ�� !!)

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	std::cout << __FUNCSIG__ << std::endl;
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 3;
	
	// �Ʒ� �ڵ带 ���� �����Ǵ� chronometry �Լ��� ���� ĳ���� �ڵ带 ������ ������
	chronometry(foo, 10);
				// => 10 �� rvalue, T=int, T&&=int&&
				// => chronometry(F f, int&& arg) �Լ� ����
				// => static_cast<int&&>(arg) �̹Ƿ� arg �� rvalue �� ĳ�����ϴ� �ڵ�
				  
	chronometry(goo, n);
				// => n �� lvalue, T=int&, T&&=int& && => int&
				// => chronometry(F f, int& arg) �Լ� ����
				// => static_cast<int&>(arg) �̹Ƿ� arg �� lvalue �� ĳ�����ϴ� �ڵ�

}
