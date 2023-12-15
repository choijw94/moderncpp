#include <iostream>
#include <type_traits>

// 최대 공약수를 구하는 함수를 생각해 봅시다. (구현생략)
// => 최대 공약수 개념은 "정수" 에만 적용됩니다
// => gcd template 을 실수를 사용할수 없게 해 봅시다.

template<typename T> T gcd(T a, T b)
{
	// 방법 1. static_assert
	// => static_assert 는 조건을 만족하지 않으면 에러입니다.
	// => static_assert 는 조건을 만족하지 에러를 내지 말고, 후보군에서 제외된다면
	//    어떨까요 ?
	static_assert(std::is_integral_v<T>, "error not integer");

	return 0;
}

void gcd(double a, double b) { std::cout << "double\n"; }

int main()
{
	gcd(6, 9);		// T 버전 사용
	gcd(3.1,  5.4); // double 버전 사용
	gcd(3.1f, 5.4f); // T 버전 사용, 그런데, 정수타입이 아니므로 static_assert 실패. 에러
}