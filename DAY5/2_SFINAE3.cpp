#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

/*
template<typename T>
int foo(T a) 
{ 
	typename T::type n;	 // SFINAE �� ����ɱ�� ?
						 // �ƴϸ� �����ϱ�� ?
						// => ���� �Դϴ�.
	return 0; 
}
*/

// SFINAE �� "�Լ� signature" ������ �����մϴ�
// 1. return type
// 2. �Լ� ����
// 3. ���ø� ����

// 1. �Ʒ� �ڵ�� T=int ��� "return type" ����� ���� �մϴ�. - SFINAE ����
template<typename T>
typename T::type foo(T a) { return 0; }

// 2. �Լ� ���� ����
template<typename T>
int foo(T a, typename T::type b = 0) { return 0; }

// 3. ���ø� ���� ����
template<typename T, typename T2 = typename T::type >
int foo(T a) { return 0; }

int main()
{
	foo(3);
}