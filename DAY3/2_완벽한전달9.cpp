#include <iostream>

void foo(int a, double d, int& r) { r = 300; }


// forwarding �ϴ� ���� ������ ������ ���ַ���
// => �������� ���ø�(variadic template) ����� ����ϼ���(�ݿ��Ͽ� ���Ե˴ϴ�)

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f(std::forward<T>(arg)... );
}

int main()
{
	int n = 3;

	chronometry(foo, 3, 3.4, n); // foo(3, 3.4, n) �� �ǹ�

	std::cout << n << std::endl; // 300

}
