#include <iostream>

// T�� Ÿ�������ϴ� ���
template<typename T> void foo(T a)
{
	// #1. RTTI ��� ���
	std::cout << typeid(T).name() << std::endl;
}

int main()
{
	// #1. Ÿ�����ڸ� ��������� �����ϴ� ���
	// => ����ڰ� ������ Ÿ�� ���
	foo<int>(3.4); // T = int

	
	// #2. Ÿ�����ڸ� �������� ���� ���. 
	// => �Լ� ���ڸ� ����ؼ� T �� Ÿ���� ����
	foo(10); // T = int 
	foo(3.4);// T = double

}