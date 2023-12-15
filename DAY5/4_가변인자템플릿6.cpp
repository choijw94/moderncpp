#include <iostream>

// recursion 
// 1. ��� ���ڸ� �������ڷ� ���� ����
// 2. 1��° ���ڴ� ������ ����(�̸��ִ� ����) �� ��������

// ���� : �Ʒ� �ڵ�� ��� ȣ���� �ƴմϴ�
// main => foo(����3��) => foo(����2��) => foo(�����Ѱ�) => foo() ���·� ȣ��..
// => ��, ��� �ٸ� �Լ� ȣ��

void foo() {}

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value;

//	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()		==> �� ��츦 ���ؼ� ���ھ��� foo �ʿ�

	// C++17 ���ʹ� �Ʒ� ó�� �ϸ� "���� ���� foo()" �� �ʿ� �����ϴ�
	// => if constexpr ����� ����Ϸ��� C++17 �̻�..
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A'); // value : 1,  args : 3.4,  'A'
}





