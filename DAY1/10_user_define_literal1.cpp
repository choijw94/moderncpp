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
	float f = 3.4f; // f ���̻� : 3.4 �� Ÿ���� float �� ����� �޶�� ��.


	Meter a = 30m;	// operator""m(30) ���� ����˴ϴ�.
//	Gram  b = 30g;
}




