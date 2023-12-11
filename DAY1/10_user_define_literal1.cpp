#include <iostream>

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};

Meter operator""m(int value)
{
	return Meter(value);
}

int main()
{
	double d = 3.4;
	float f = 3.4f; // f 접미사 : 3.4 의 타입을 float 로 취급해 달라는 것.


	Meter a = 30m;	// operator""m(30) 으로 변경됩니다.
//	Gram  b = 30g;
}




