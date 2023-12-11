// 17_static_if3
#include <iostream>
#include <type_traits>

template<typename T> 
void foo(T a)
{
	// T 타입의 특성에 따른 최적화된 알고리즘을 작성합니다.
	if constexpr (std::is_pointer_v<T>)
	{
		std::cout << "포인터에 최적화된 알고리즘\n";
	}
	else if constexpr (std::is_integral_v<T>)
	{
		std::cout << "정수에 최적화된 알고리즘\n";
	}
	else 
	{
		std::cout << "그외에 타입에 대한 알고리즘\n";
	}
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
	foo(3.4);
}

// if           : 조건이 false 라면 실행안함
// if constexpr : 조건이 false 라면 템플릿 인스턴스화에 참여 안함.

// constexpr 의 3가지 용도
// 1. constexpr 상수 - C++11
// 2. constexpr 함수 - C++11
// 3. constexpr if   - C++17