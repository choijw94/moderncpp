#include <iostream>
#include "stopwatch.h"	// git ���� ��������
						// DAY3 ������ ������ ��������

void foo(int a, double d, int& r) 
{ 
	for (int i = 0; i < a; ++i)
	{
		r = i;
	}
}

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	StopWatch sw(true);	// 1. �����ڿ��� ���� �ð��� ���ؼ� �����մϴ�.
						// 2. ������ ���ڷ� true �� �����ϸ�
						//    �Ҹ��ڿ��� �ٽ� �ð��� ���ؼ� 1���� ���� �ð����� ���̸� ����մϴ�
						// 3. sw �� �Ҹ��ڴ� �Ʒ� f(...) �� ������� ȣ��˴ϴ�.

	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 3;

	chronometry(foo, 1000000, 3.4, n);  // foo(1000000, 3.4, n);

	std::cout << n << std::endl; 

}
