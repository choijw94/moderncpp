#include <iostream>
#include <type_traits>

// �ִ� ������� ���ϴ� �Լ��� ������ ���ô�. (��������)
// => �ִ� ����� ������ "����" ���� ����˴ϴ�
// => gcd template �� �Ǽ��� ����Ҽ� ���� �� ���ô�.

template<typename T> T gcd(T a, T b)
{
	// ��� 1. static_assert
	static_assert(std::is_integral_v<T>, "error not integer");

	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
}