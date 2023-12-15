#include <iostream>


template<typename T>
typename T::type foo(T a)  { std::cout << "T" << std::endl; return 0; }
//    int::type foo(int a) { .... }

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	// � �Լ��� ������� �����Ҷ��� "�Լ� ����"�� ���� �Ǵ��ϰ� �˴ϴ�.
	foo(3); // 1. �����Ϸ��� T ����ϱ�� ����
			// 2. T=int �� �����ϰ� �Լ� ����
			// 3. �Լ� ������ ���� Ÿ���� "int::type" �̵ǹǷ� �Լ� ��������
			// => �̶� "����" �� �ƴ϶� �ĺ������� ���ܵǰ�
			//    foo(...) �� ����ϰ� �˴ϴ�.

	// Substitution Failure Is Not An Error
	// => ġȯ ���д� ������ �ƴϴ�.
	// => SFINAE
}