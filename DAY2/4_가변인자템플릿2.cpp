#include <iostream>

// �Ʒ� ó�� ����� foo �� 
// => "���ڸ� �Ѱ��� ������ �ִ� ���ø�(Ʋ)"

// template<typename T> void foo(T args) { }


// �Ʒ� �ڵ�� ���� ������ ������� �Լ� ������ ������ Ʋ(���ø�)
// => ���ڸ� � ���·� �����ص� �Լ� ������ ����
template<typename ... Types> 
void foo(Types ... args) 
{
}

int main()
{	
	foo(1);
	foo(1, 2);	
	foo(1, 2, 3);
	foo(1, 3.4, 'A');
}