// ������ȯ - 73 page �Ʒ� �κ�
#include <iostream>

// �Ʒ� �ڵ忡�� ��ȯ Ÿ�� ? �� ��� ǥ���ؾ� �ұ�� ?
template<typename T1, typename T2>
// ? Mul(T1 a, T2 b)
decltype( a * b ) Mul(T1 a, T2 b) // �� �����ϱ�� ??
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

