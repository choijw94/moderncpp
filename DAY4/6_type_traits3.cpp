#include <iostream>
#include <type_traits> // 이 헤더에 많은 traits 가 이미 만들어져 있습니다.
					   // C++11 에서 제공되는 헤더

// cppreference.com 에서 1번째 화면에서 type_tratis 선택해 보세요


template<typename T> void printv(const T& v)
{
	// if : 실행시간 조건문, 컴파일 시간에 조건이 false 로 결정되어도
	//      템플릿 => 실제 함수 를 만들때는 포함됩니다.
	//      단지, 실행만 안되는 것

	// if constexpr : 컴파일 조건문, 컴파일 시간에 조건이 false 로 결정되면
	//				  템플릿 = > 실제 함수 를 만들때는 포함 안됨.
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

