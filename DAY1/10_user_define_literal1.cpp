#include <iostream>

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}

	Meter operator-() { return Meter(-value); }
};

// �ٽ� 1. ������ Ÿ���� ǥ�ؿ� ���� ��ӵǾ� �ֽ��ϴ�.
//   => ������ ���ͷ��� ���̻縦 ���鶧�� "unsigned long long"
// 
// 2. �ǵ����̸� �Ϲ� �����ڴ� ���ο� ���̻縦 ������ ������..
//    => ǥ�� ���̺귯 ������ ����ϱ� ���ؼ� ���� ����
//    => ����ڰ� ������� _ �� ���� �ؾ� �մϴ�.

Meter operator""_m(unsigned long long value)
{
	return Meter(static_cast<int>(value));
}

int main()
{
	Meter a = -30_m;	// operator""m(30) ���� ����˴ϴ�.
//	Gram  b = 30g;

	double d = 3.4;
	float f = 3.4f; // f ���̻� : 3.4 �� Ÿ���� float �� ����� �޶�� ��.

	-30_m;  // -(operator""m(30));
			// -(meter��ü)  => meter��ü.operator-()
}




