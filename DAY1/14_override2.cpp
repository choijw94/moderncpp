#include <iostream>

template<typename T>
class Base
{
public:
	virtual void foo(const T p)
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Derived : public Base<int*>
{
public:
	// foo �������ϼ��� "Derived foo" ���, override Ű���� ������� ������
};
int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);
}