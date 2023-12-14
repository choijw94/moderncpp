#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

// #1. 일반 함수는 동작만 있고 상태가 없습니다.
bool foo(int n) { return n % 3 == 0; }

// #2. 함수 객체는 동작과 "상태(멤버 데이타)" 가 있습니다.
struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	// () 연산자 함수가 인자가 한개이므로 단항 함수객체 입니다.
	bool operator()(int n) const
	{
		return n % value == 0;
	}
};




int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	
	IsDivide f(k); // f 는 k의 값을 내부적으로 보관합니다.
	
	bool b = f(10); // 10 % k(3) 의 연산 수행.. 즉, k 로 나누어 떨어지는가 조사.
	
	auto p1 = std::find_if(v.begin(), v.end(), f );

	// 한번만 사용한다면 아래처럼 임시객체로 전달하는 것이 좋습니다.
	auto p2 = std::find_if(v.begin(), v.end(), IsDivide(k) ); /// <<==== A
}

// 위 코드 "A" 부분의 마지막 인자를 생각해 보면
// => find_if( first, last, "main지역변수 k + 단항함수") 를 전달하는 의미 입니다.

// closure(클로져)
// => 자신이 속한 문맥의 지역변수를 캡쳐할수 있는 능력이 있는 함수.. 
// => IsDivide 는 main 함수의 k 를 캡쳐하고 있습니다.

// C++에서 일반함수 : 클로져가 될수 없습니다.
// C++에서 함수객체 : 클로져가 될수 있습니다.

// closure 는 C++ 뿐 아니라 대부분의 언어가 사용하는 용어 입니다.

