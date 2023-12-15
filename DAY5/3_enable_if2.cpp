#include <iostream>
#include <type_traits>

// �ִ� ������� ���ϴ� �Լ��� ������ ���ô�. (��������)
// => �ִ� ����� ������ "����" ���� ����˴ϴ�
// => gcd template �� �Ǽ��� ����Ҽ� ���� �� ���ô�.

template<typename T> T gcd(T a, T b)
{
	// ��� 1. static_assert
	// => static_assert �� ������ �������� ������ �����Դϴ�.
	// => static_assert �� ������ �������� ������ ���� ����, �ĺ������� ���ܵȴٸ�
	//    ���� ?
	static_assert(std::is_integral_v<T>, "error not integer");

	return 0;
}

void gcd(double a, double b) { std::cout << "double\n"; }

int main()
{
	gcd(6, 9);		// T ���� ���
	gcd(3.1,  5.4); // double ���� ���
	gcd(3.1f, 5.4f); // T ���� ���, �׷���, ����Ÿ���� �ƴϹǷ� static_assert ����. ����
}