#include <iostream>

// recursion 
// 1. ��� ���ڸ� �������ڷ� ���� ����
// 2. 1��° ���ڴ� ������ ����(�̸��ִ� ����) �� ��������

void foo() {}

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value;

	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()		==> �� ��츦 ���ؼ� ���ھ��� foo �ʿ�
}

int main()
{
	foo(1, 3.4, 'A'); // value : 1,  args : 3.4,  'A'
}





