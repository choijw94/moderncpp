#include <iostream>
#include <type_traits>
// 모든 포인터를 제거한 타입을 구해 봅시다.
// => C++ 표준에는 아래 코드는 없습니다.!!! 
// => C++ 표준에는 remove_pointer 만 있습니다.

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
