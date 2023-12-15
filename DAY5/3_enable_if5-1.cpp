#include <iostream>
#include <type_traits>

// C++ ���������� "enable_if" ����� �߿��ϴٴ� ���� ���ݰ� �Ǿ����ϴ�.
// 
// => ��� Ÿ�Կ� ���ؼ� ��밡���� ���ø��� �ƴ�
// => ������ �����ϴ� Ÿ�Կ� ���ؼ��� ��밡���� ���ø��� ������.!!

// �׷��� C++20 ���� enable_if �� ���� ������ ����Ҽ� �ִ�
// => "requires clause" �� ������ �����߽��ϴ�.


template<typename T> requires std::is_pointer_v<T> 
void printv(const T& v)
{
	std::cout << "������ ����\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
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

