#include <iostream>
#include <type_traits>

/*
template<typename T> void printv(const T& v)
{
	// �Ʒ� ó�� ����� T=int �϶�
	// => �ν��Ͻ�ȭ�� �Լ��� "*v" �� ���ԵǾ ���� �Դϴ�.
	// => �� ������ �ذ��ϱ� ���� ���� Ű���尡 "if constexpr" �Դϴ�. (�Ʒ� ����)
	if (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/

/*
template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/

// if constexpr �� C++17 ���� ���� �˴ϴ�.
// C++17 �������� "enable_if" �� �ذ��߽��ϴ�.

template<typename T> 
std::enable_if< std::is_pointer_v<T> >
printv(const T& v)
{
	std::cout << "������ ����\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> 
std::enable_if<!std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << "������ �ƴ� ����\n";
	std::cout << v << std::endl;
}



int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

