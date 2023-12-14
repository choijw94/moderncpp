// 4_type_traits3 - 210 page
#include <iostream>

// 표준  traits 를 사용하려면
#include <type_traits>

template<typename T> void foo(T a)
{
	// 1. 조사하려면
	bool b1 = std::is_pointer<T>::value; // C++11 스타일
	bool b2 = std::is_pointer_v<T>;      // C++17 스타일 


	// 2. 변형 타입을 얻으려면
	typename std::remove_pointer<T>::type n1; // C++11 스타일


	remove_pointer_t<T> n2; // 위와 동일   C++14 스타일

	std::remove_
}

int main()
{
	int n = 0;
	foo(&n);
}

// C++14 에서 remove_pointer 등을 쉽게 사용하기 위한 alias 를 제공합니다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;
