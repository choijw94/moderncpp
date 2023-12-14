#include <iostream>

int main()
{
	
	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2); // ������ �ƴ����� ����� 6


	// generic lambda 
	// => ����ǥ���� ���ڷ� auto �� ����ϴ� ���
	// => C++14 ���� ����
	auto f1 = [](auto a, auto b) { return a + b; };

	std::cout << f1(1,   2)   << std::endl; // 3
	std::cout << f1(1.1, 2.1) << std::endl; // 3.3
	std::cout << f1(1.1, 2)   << std::endl; // 3.1
	std::cout << f1(1,   2.1) << std::endl; // 3.1
}