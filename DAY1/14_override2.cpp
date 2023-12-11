#include <iostream>

template<typename T>
class Base
{
public:
	virtual void foo(const T a)
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Derived : public Base<int*>
{
public:
	// foo �������ϼ��� "Derived foo" ���, override Ű���� ������� ������
	virtual void foo(const int* a)
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);	// "Derived foo" �������� Derived �ȿ� foo ���弼��
}