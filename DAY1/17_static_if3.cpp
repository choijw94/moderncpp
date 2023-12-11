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