#include <iostream>
#include <type_traits>

// C++ 진영에서는 "enable_if" 기술이 중요하다는 것을 깨닫게 되었습니다.
// 
// => 모든 타입에 대해서 사용가능한 템플릿이 아닌
// => 조건을 만족하는 타입에 대해서만 사용가능한 템플릿을 만들자.!!

// 그래서 C++20 에서 enable_if 를 보다 간단히 사용할수 있는
// => "requires clause" 는 문법을 도입했습니다.


template<typename T> requires std::is_pointer_v<T> 
void printv(const T& v)
{
	std::cout << "포인터 버전\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
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

