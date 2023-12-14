#include <iostream>
#include <type_traits>

// type traits : 타입(T) 에 대한 다양한 특성(특질)을 조사하는 기술

// 만드는 법 : 대부분 아래와 유사한 원리로 만들게 됩니다.
// 
// 1. primary template 에서는 false 반환(value = false 라는 의미)
// 2. 조건을 만족하도록 부분 특수화 버전을 제공하고 true 반환

template<typename T> struct is_pointer
{
//	enum { value = false }; // 왜 enum 을 사용하나요 ?

//	bool value = false;	    // 1. C++11 이전에는 이 위치에서 초기화 할수 없고
							// 2. 이렇게 하면 "컴파일 시간 상수" 가 아닙니다.
							// => C++11 이전에, 구조체 안에서 초기화 되고,
							//    컴파일 시간 상수로 사용하는 유일한 방법이 enum 입니다.

	// C++11 이후는 아래 처럼 구현합니다.
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
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}