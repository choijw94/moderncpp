// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits �� ����
// 1. Ÿ������ : is_xxx<T>::value
// 2. ����Ÿ�Ծ�� : xxx<T>::type

// ���� Ÿ���� ���� traits �����

template<typename T> struct remove_pointer
{
	using type = T;
};

template<typename T> struct remove_pointer<T*>
{
	using type = T;
};

int main()
{
	remove_pointer<int*>::type n2;  // int n2
}

template<typename T> void foo(T a)
{
	// ���� : ���� Ÿ���� ��� traits �� �ᱹ "��"�� �ƴ� "Ÿ��"�� ��� �˴ϴ�.
	//		���ø� ���� �̸��� ����Ѵٸ� "typename" �ʿ� �մϴ�.

	remove_pointer<T>::type n1; // error
	typename remove_pointer<T>::type n1; // ok.
}