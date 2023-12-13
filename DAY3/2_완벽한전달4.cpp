#include <iostream>

void hoo(int&& a) {}


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

//	main					chronometry						    hoo(int&&)
//  hoo(10) =====================================================> ok
//  chrometry(10) =========> int&& arg = 10
//								hoo(arg) =========================> error
//								hoo(static_cast<int&&>(arg)) =====> ok. 

template<typename F>
void chronometry(F f, int&& arg)
{
	// int&& arg = 10 ���� 
	// 10  : rvalue
	// arg : lvalue. <<==== �ٽ�!

//	f(arg);	// arg�� lvalue �̹Ƿ�
			// hoo(int&) �Ǵ� hoo(int) �� ã�� �Ǵϴ�.

	// main ������ rvalue(10) �� ���´µ�, �����鼭 �̸��� �����, lvalue �� �Ȱ���
	// �ٽ� rvalue �� �����ؼ� �����մϴ�.
	f(static_cast<int&&>(arg)); // ok
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10);	
}
