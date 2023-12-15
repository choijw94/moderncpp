#include <iostream>
#include <type_traits>

// 최대 공약수를 구하는 함수를 생각해 봅시다. (구현생략)
// => 최대 공약수 개념은 "정수" 에만 적용됩니다
// => gcd template 을 실수를 사용할수 없게 해 봅시다.

template<typename T> T gcd(T a, T b)
{
	// 방법 1. static_assert
	static_assert(std::is_integral_v<T>, "error not integer");

	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
}