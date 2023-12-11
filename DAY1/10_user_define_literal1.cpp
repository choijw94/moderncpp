#include <iostream>

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}

	Meter operator-() { return Meter(-value); }
};

// 핵심 1. 인자의 타입이 표준에 의해 약속되어 있습니다.
//   => 정수형 리터럴의 접미사를 만들때는 "unsigned long long"
// 
// 2. 되도록이면 일반 개발자는 새로운 접미사를 만들지 마세요..
//    => 표준 라이브러 에서만 사용하기 위해서 만든 문법
//    => 사용자가 만들려면 _ 로 시작 해야 합니다.

Meter operator""_m(unsigned long long value)
{
	return Meter(static_cast<int>(value));
}

int main()
{
	Meter a = -30_m;	// operator""m(30) 으로 변경됩니다.
//	Gram  b = 30g;

	double d = 3.4;
	float f = 3.4f; // f 접미사 : 3.4 의 타입을 float 로 취급해 달라는 것.

	-30_m;  // -(operator""m(30));
			// -(meter객체)  => meter객체.operator-()
}




