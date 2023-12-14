#include <iostream>
#include <type_traits>

// type traits : Ÿ��(T) �� ���� �پ��� Ư��(Ư��)�� �����ϴ� ���

// ����� �� : ��κ� �Ʒ��� ������ ������ ����� �˴ϴ�.
// 
// 1. primary template ������ false ��ȯ(value = false ��� �ǹ�)
// 2. ������ �����ϵ��� �κ� Ư��ȭ ������ �����ϰ� true ��ȯ

template<typename T> struct is_pointer
{
//	enum { value = false }; // �� enum �� ����ϳ��� ?

//	bool value = false;	    // 1. C++11 �������� �� ��ġ���� �ʱ�ȭ �Ҽ� ����
							// 2. �̷��� �ϸ� "������ �ð� ���" �� �ƴմϴ�.
							// => C++11 ������, ����ü �ȿ��� �ʱ�ȭ �ǰ�,
							//    ������ �ð� ����� ����ϴ� ������ ����� enum �Դϴ�.

	// C++11 ���Ĵ� �Ʒ� ó�� �����մϴ�.
	static constexpr bool value = false;
};



template<typename T> struct is_pointer<T*>
{
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// T : int, int*
	
	if ( is_pointer<T>::value )
		std::cout << "������" << std::endl;
	else
		std::cout << "������ �ƴ�" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}