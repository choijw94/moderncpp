// 17_static_if3
#include <iostream>
#include <type_traits>

template<typename T> 
void foo(T a)
{
	// T Ÿ���� Ư���� ���� ����ȭ�� �˰����� �ۼ��մϴ�.
	if constexpr (std::is_pointer_v<T>)
	{
		std::cout << "�����Ϳ� ����ȭ�� �˰���\n";
	}
	else if constexpr (std::is_integral_v<T>)
	{
		std::cout << "������ ����ȭ�� �˰���\n";
	}
	else 
	{
		std::cout << "�׿ܿ� Ÿ�Կ� ���� �˰���\n";
	}
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
	foo(3.4);
}

// if           : ������ false ��� �������
// if constexpr : ������ false ��� ���ø� �ν��Ͻ�ȭ�� ���� ����.

// constexpr �� 3���� �뵵
// 1. constexpr ��� - C++11
// 2. constexpr �Լ� - C++11
// 3. constexpr if   - C++17