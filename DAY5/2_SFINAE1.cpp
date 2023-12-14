// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3); // 1. foo(int) ��� - exactly matching
			// 2. foo(T) - template �� ����ؼ� foo(int) ����
			// 3. ...
			
	// �� ó�� �����̸��� �Լ��� ������ ������, 
	// �Լ�ã�� ��Ģ�� "overloading resolution" �̶�� �մϴ�.
}