#include <iostream>
#include <type_traits> // 이 헤더에 많은 traits 가 이미 만들어져 있습니다.
					   // C++11 에서 제공되는 헤더

// cppreference.com 에서 1번째 화면에서 type_tratis 선택해 보세요


template<typename T> void printv(const T& v)
{
	if ( std::is_pointer<T>::value )

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

