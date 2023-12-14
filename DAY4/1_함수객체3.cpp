#include <iostream>
#include <vector>
#include <algorithm>

// �Լ���ü�� ���� 1. Closure

// #1. �Ϲ� �Լ��� ���۸� �ְ� ���°� �����ϴ�.
bool foo(int n) { return n % 3 == 0; }

// #2. �Լ� ��ü�� ���۰� "����(��� ����Ÿ)" �� �ֽ��ϴ�.
struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	// () ������ �Լ��� ���ڰ� �Ѱ��̹Ƿ� ���� �Լ���ü �Դϴ�.
	bool operator()(int n) const
	{
		return n % value == 0;
	}
};




int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	
	IsDivide f(k); // f �� k�� ���� ���������� �����մϴ�.
	
	bool b = f(10); // 10 % k(3) �� ���� ����.. ��, k �� ������ �������°� ����.
	
	auto p1 = std::find_if(v.begin(), v.end(), f );

	// �ѹ��� ����Ѵٸ� �Ʒ�ó�� �ӽð�ü�� �����ϴ� ���� �����ϴ�.
	auto p2 = std::find_if(v.begin(), v.end(), IsDivide(k) ); /// <<==== A
}

// �� �ڵ� "A" �κ��� ������ ���ڸ� ������ ����
// => find_if( first, last, "main�������� k + �����Լ�") �� �����ϴ� �ǹ� �Դϴ�.

// closure(Ŭ����)
// => �ڽ��� ���� ������ ���������� ĸ���Ҽ� �ִ� �ɷ��� �ִ� �Լ�.. 
// => IsDivide �� main �Լ��� k �� ĸ���ϰ� �ֽ��ϴ�.

// C++���� �Ϲ��Լ� : Ŭ������ �ɼ� �����ϴ�.
// C++���� �Լ���ü : Ŭ������ �ɼ� �ֽ��ϴ�.

// closure �� C++ �� �ƴ϶� ��κ��� �� ����ϴ� ��� �Դϴ�.

