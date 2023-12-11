#include <iostream>
/*
int n = 0;

// #1. �Ʒ� 2�� ������ ��Ȯ�� �˾ƾ� �մϴ�.
const int* p1 = &n; // p1�� ���󰡸� const, p1 ��ü�� ��� �ƴ�.
int* const p2 = &n; // p2�� const,         p2�� ����Ű�� ���� const �ƴ�.

// #2. const Ÿ���� �� �Ǵ� �ڿ� ǥ���ص� �˴ϴ�.
const int c1 = 10;
int const c2 = 10; // c1, c2 �� ����

const int* p1 = &n;
int const* p2 = &n;  // p1, p2 �� ����
int* const p3 = &n;  // p3�� p1, p2 �� �ٸ�. * ��ġ �� ����
*/
//==============================================================

template<typename T>
class Base
{
public:
	// "a �� const" ��� �ǹ� �Դϴ�.
	virtual void foo(const T a)
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Derived : public Base<int*>
{
public:
	// foo �������ϼ��� "Derived foo" ���, override Ű���� ������� ������
	// => �Ʒ� ������ �ڵ�� �߸��� ������ �Դϴ�.
	// => "override" Ű���带 ����ߴٸ� "�߸��Ǿ��ٴ� ����� �ٷ� �˾Ƴ��� �ֽ��ϴ�."
	// => "override" Ű���带 ������ ������, �߸��Ǿ��ٴ� ���� �ٷ� �˼� �����ϴ�.

//	virtual void foo(const int* a)	// a�� ����Ű�� ���� const 
	virtual void foo(int* const a)	// a�� const. �� �ڵ尡 ��� Ŭ���� �Լ��� override �Ѱ�
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);	// "Derived foo" �������� Derived �ȿ� foo ���弼��
}