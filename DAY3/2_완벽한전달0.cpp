#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int&& r = 10;	// 10 �� rvalue
					// r  �� lvalue

	foo(r);	// r�� Ÿ���� int&& ����, value �Ӽ��� lvalue �̹Ƿ�
			// foo(int&) ȣ��.

	foo(static_cast<int&&>(r)); // foo(int&&) ȣ��
	
	// static_cast<int&&>(r) �� 
	// => Ÿ��ĳ������ �ƴ� value ĳ����(lvalue => rvalue(��Ȯ���� xvalue))

}







