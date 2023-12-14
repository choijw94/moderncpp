// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// 변형 타입을 얻은 traits 만들기

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
	// 주의 : 변형 타입을 얻는 traits 는 결국 "값"이 아닌 "타입"을 얻게 됩니다.
	//		템플릿 의존 이름을 사용한다면 "typename" 필요 합니다.

	remove_pointer<T>::type n1; // error
	typename remove_pointer<T>::type n1; // ok.
}