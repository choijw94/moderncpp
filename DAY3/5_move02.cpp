#include <iostream>
#include <string>
#include <vector>

// �� move�� �߿��Ѱ� ? - 101 page �Ʒ� �ֽ��ϴ�.

// �Ʒ� �ڵ�� "����" ����� swap �Դϴ�(C++98 ������ C++ ǥ�� ����)
// => ������ ���� �ʽ��ϴ�.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;	// T Ÿ���� ���� ������ ȣ��
				// string �̾��ٸ� "���ڿ�"�� ���� ����
	a = b;
	b = tmp;
}

// �Ʒ� �ڵ�� C++11 ������ swap ����
// �̵��� ����� swap �Դϴ�.
// ���� �������� �����ϴ�.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);	
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}



