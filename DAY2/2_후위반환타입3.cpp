#include <iostream>

// #1. auto 만 표기하면
// => 반환 타입을 return 문장을 보고 추론해 달라.
// => return 문장이 2개 이상 있으면 에러
// => auto 추론이므로 "a*b" 의 결과가 reference 이면 reference 제거후 타입 결정
template<typename T1, typename T2>
auto  Mul1(T1 a, T2 b)
{
//	if (a == 1) return b;
	return a * b;
}

// #2. decltype(auto) 만 표기하면
// => 위와 같이 return 문장으로 타입 결정, return이 2개 이상이면 에러
// => auto 가 아닌 decltype 규칙으로 타입 결정
template<typename T1, typename T2>
decltype(auto) Mul2(T1 a, T2 b)
{
	return a * b;
}

// #3. 후위 반환 타입을 사용한 경우
// => return 문을 보고 타입을 결정하지 말고
// => decltype(a*b) 를 반환 타입으로 하겠다는것,
// => 즉, 반환 타입을 표기한것
template<typename T1, typename T2>
auto  Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

int main()
{
}

