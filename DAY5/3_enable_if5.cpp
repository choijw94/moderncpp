#include <iostream>
#include <type_traits>

/*
template<typename T> void printv(const T& v)
{
	// 아래 처럼 만들면 T=int 일때
	// => 인스턴스화된 함수에 "*v" 가 포함되어서 에러 입니다.
	// => 이 문제를 해결하기 위해 나온 키워드가 "if constexpr" 입니다. (아래 버전)
	if (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/

/*
template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/

// if constexpr 은 C++17 부터 지원 됩니다.
// C++17 이전에는 "enable_if" 로 해결했습니다.

template<typename T> 
std::enable_if< std::is_pointer_v<T> >
printv(const T& v)
{
	std::cout << "포인터 버전\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> 
std::enable_if<!std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << "포인터 아닌 버전\n";
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

