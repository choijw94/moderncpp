#include <iostream>
#include <type_traits>

// enable_if 기술 사용법
// std::enable_if<조건, "타입">::type 의 최종 결과는
//                조건이 참이면   : ?
//                조건이 거짓이면 : ?


// 아래 리턴 타입의 코드가 핵심입니다.
template<typename T> 

std::enable_if< std::is_integral_v<T>, T>::type

gcd(T a, T b)
{
	return 0;
}

void gcd(double a, double b) { std::cout << "double\n"; }

int main()
{
	gcd(6, 9);		
	gcd(3.1, 5.4); 
	gcd(3.1f, 5.4f); 
}