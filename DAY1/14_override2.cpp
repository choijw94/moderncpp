#include <iostream>
/*
int n = 0;

// #1. 아래 2개 차이점 명확히 알아야 합니다.
const int* p1 = &n; // p1을 따라가면 const, p1 자체는 상수 아님.
int* const p2 = &n; // p2가 const,         p2가 가리키는 곳은 const 아님.

// #2. const 타입의 앞 또는 뒤에 표시해도 됩니다.
const int c1 = 10;
int const c2 = 10; // c1, c2 는 동일

const int* p1 = &n;
int const* p2 = &n;  // p1, p2 는 동일
int* const p3 = &n;  // p3는 p1, p2 와 다름. * 위치 에 주의
*/
//==============================================================

template<typename T>
class Base
{
public:
	// "a 가 const" 라는 의미 입니다.
	virtual void foo(const T a)
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Derived : public Base<int*>
{
public:
	// foo 재정의하세요 "Derived foo" 출력, override 키워드 사용하지 마세요
	// => 아래 재정의 코드는 잘못된 재정의 입니다.
	// => "override" 키워드를 사용했다면 "잘못되었다는 사실을 바로 알아낼수 있습니다."
	// => "override" 키워드를 붙이지 않으면, 잘못되었다는 것을 바로 알수 없습니다.

//	virtual void foo(const int* a)	// a가 가리키는 곳이 const 
	virtual void foo(int* const a)	// a가 const. 이 코드가 기반 클래스 함수를 override 한것
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);	// "Derived foo" 나오도록 Derived 안에 foo 만드세요
}