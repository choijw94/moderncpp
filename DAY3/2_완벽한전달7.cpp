#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// �ٽ� ����
// => �Ϻ��� ����(perfect forwarding) ����� ����Ϸ���

// 1. ���ڸ� ������ "T&&(forwarding reference)" �� ��������
// 2. ���� ���ڸ� �ٸ� �Լ��� ������ "std::forward<T>(arg)" �� ��� ��������

// ����
// std::forward �� ���ڰ� rvalue �� �� ���� ���ؼ� �ʿ� �մϴ�.
//                       lvalue �϶��� ��� �Ǳ� �մϴ�.
// ������ ��� ��츦 ����ؾ� �ϹǷ� �ݵ�� "std::forward" ����ϼ���. 

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f( std::forward<T>(arg) );  
}


int main()
{
	int n = 3;

	chronometry(foo, 10);

	chronometry(goo, n);

}
