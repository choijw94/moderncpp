#include <iostream>

// #1. auto �� ǥ���ϸ�
// => ��ȯ Ÿ���� return ������ ���� �߷��� �޶�.
// => return ������ 2�� �̻� ������ ����
// => auto �߷��̹Ƿ� "a*b" �� ����� reference �̸� reference ������ Ÿ�� ����
template<typename T1, typename T2>
auto  Mul1(T1 a, T2 b)
{
//	if (a == 1) return b;
	return a * b;
}

// #2. decltype(auto) �� ǥ���ϸ�
// => ���� ���� return �������� Ÿ�� ����, return�� 2�� �̻��̸� ����
// => auto �� �ƴ� decltype ��Ģ���� Ÿ�� ����
template<typename T1, typename T2>
decltype(auto) Mul2(T1 a, T2 b)
{
	return a * b;
}

// #3. ���� ��ȯ Ÿ���� ����� ���
// => return ���� ���� Ÿ���� �������� ����
// => decltype(a*b) �� ��ȯ Ÿ������ �ϰڴٴ°�,
// => ��, ��ȯ Ÿ���� ǥ���Ѱ�
template<typename T1, typename T2>
auto  Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

int main()
{
}

