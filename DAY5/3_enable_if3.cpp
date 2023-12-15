#include <iostream>
#include <type_traits>

// enable_if 기술 사용법
// 
// std::enable_if<조건, "타입">::type 의 최종 결과는
//                조건이 참이면   : "타입"
//                조건이 거짓이면 : "::type" 자체가 없다!


// std::enable_if< std::is_integral_v<T>, T>::type
//							T 가 정수라면, 최종결과(리턴타입)은 T
//							T 가 정수가 아니면 "::type" 없음, 함수 생성 실패
//									SFINAE 규칙에 따라 에러가 아닌 후보에서 제외

// static_assert				: 조건을 만족하지 않으면 컴파일 에러
// enable_if 를 사용한 반환 타입 : 조건을 만족하지 않으면 사용하지 않겠다
//								  동일한 이름의 다른 함수가 있다면 사용가능


// 아래 리턴 타입의 코드가 핵심입니다.
template<typename T> 

//typename std::enable_if< std::is_integral_v<T>, T>::type
std::enable_if_t< std::is_integral_v<T>, T>
				
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