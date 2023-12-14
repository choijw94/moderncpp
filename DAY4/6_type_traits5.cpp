#include <iostream>
#include <type_traits>
// ��� �����͸� ������ Ÿ���� ���� ���ô�.
// => C++ ǥ�ؿ��� �Ʒ� �ڵ�� �����ϴ�.!!! 
// => C++ ǥ�ؿ��� remove_pointer �� �ֽ��ϴ�.

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{											// int**  *	
											// int*  * 
											// int  *	 	
	using type = typename remove_all_pointer<T>::type ;
};

int main()
{
	remove_all_pointer<int***>::type n;
}
