#include <iostream>
#include <type_traits>

// ���� C++�� "Ư�� Ÿ��" �� ���� �Լ� �����ε���
// ���� �մϴ�.
void foo(int)    {}
void foo(double) {}

// "Ÿ��"�� �ƴ� "Ư�� ������ �����ϴ� Ÿ�Ե�"�� ���� �����ε��� ������
// ���� ������� ?
// void goo(�����Լ����ִ�Ŭ������) {}
// void goo(�����Լ�������Ŭ������) {}

// enable_if �� ����Ϸ���, ���� Ÿ�� ��ġ�� �Ʒ� �ڵ带 ��������

// typename std::enable_if<����, ����Ÿ��>:: type   �ε�.. �̹����� ������� ���� 
// std::enable_if_t<����, ����Ÿ��>				   �� ���� ����ϼ���.
// std::enable_if_t<����>				���� Ÿ���� void �� ��� ��������									


// std::is_polymorphic_v<T> : �����Լ��� ������ true, ������ false

template<typename T>
std::enable_if_t< std::is_polymorphic_v<T>>
goo(T a)
{
	std::cout << "�����Լ��� �ִ� Ÿ�Կ� ���� �˰���\n";
}

template<typename T>
std::enable_if_t< !std::is_polymorphic_v<T>>
goo(T a)
{
	std::cout << "�����Լ��� ���� Ÿ�Կ� ���� �˰���\n";
}

class A { virtual void foo() {} };

int main()
{
	int n = 0;
	A   a;

	goo(n); // �����Լ� ���� Ÿ���� ��ü
	goo(a); // �����Լ� �ִ� Ÿ���� ��ü

}