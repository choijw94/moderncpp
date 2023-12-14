#include <iostream>
#include <type_traits> // �� ����� ���� traits �� �̹� ������� �ֽ��ϴ�.
					   // C++11 ���� �����Ǵ� ���

// cppreference.com ���� 1��° ȭ�鿡�� type_tratis ������ ������


template<typename T> void printv(const T& v)
{
	// if : ����ð� ���ǹ�, ������ �ð��� ������ false �� �����Ǿ
	//      ���ø� => ���� �Լ� �� ���鶧�� ���Ե˴ϴ�.
	//      ����, ���ุ �ȵǴ� ��

	// if constexpr : ������ ���ǹ�, ������ �ð��� ������ false �� �����Ǹ�
	//				  ���ø� = > ���� �Լ� �� ���鶧�� ���� �ȵ�.
	//                C++17
	// 
//	if ( std::is_pointer<T>::value )

	if constexpr (std::is_pointer<T>::value)

		std::cout << v << " : " << *v << std::endl;

	else
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

