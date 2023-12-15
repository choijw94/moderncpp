#include <iostream>
#include <type_traits>

// 현재 C++은 "특정 타입" 에 따른 함수 오버로딩을
// 지원 합니다.
void foo(int)    {}
void foo(double) {}

// "타입"이 아닌 "특정 조건을 만족하는 타입들"에 따른 오버로딩은 있으면
// 좋지 않을까요 ?
// void goo(가상함수가있는클래스들) {}
// void goo(가상함수가없는클래스들) {}

// enable_if 를 사용하려면, 리턴 타입 위치에 아래 코드를 적으세요

// typename std::enable_if<조건, 리턴타입>:: type   인데.. 이버전을 사용하지 말고 
// std::enable_if_t<조건, 리턴타입>				   이 버전 사용하세요.
// std::enable_if_t<조건>				리턴 타입이 void 인 경우 생략가능									


// std::is_polymorphic_v<T> : 가상함수가 있으면 true, 없으면 false

template<typename T>
std::enable_if_t< std::is_polymorphic_v<T>>
goo(T a)
{
	std::cout << "가상함수가 있는 타입에 대한 알고리즘\n";
}

template<typename T>
std::enable_if_t< !std::is_polymorphic_v<T>>
goo(T a)
{
	std::cout << "가상함수가 없는 타입에 대한 알고리즘\n";
}

class A { virtual void foo() {} };

int main()
{
	int n = 0;
	A   a;

	goo(n); // 가상함수 없는 타입의 객체
	goo(a); // 가상함수 있는 타입의 객체

}