// 4_type_traits3 - 210 page
#include <iostream>

// ǥ��  traits �� ����Ϸ���
#include <type_traits>

template<typename T> void foo(T a)
{
	// 1. �����Ϸ���
	bool b1 = std::is_pointer<T>::value; // C++11 ��Ÿ��
	bool b2 = std::is_pointer_v<T>;      // C++17 ��Ÿ�� 


	// 2. ���� Ÿ���� ��������
	typename std::remove_pointer<T>::type n1; // C++11 ��Ÿ��


	remove_pointer_t<T> n2; // ���� ����   C++14 ��Ÿ��

	std::remove_
}

int main()
{
	int n = 0;
	foo(&n);
}

// C++14 ���� remove_pointer ���� ���� ����ϱ� ���� alias �� �����մϴ�.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;
