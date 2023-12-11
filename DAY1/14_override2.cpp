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
	// foo 재정의하세요 "Derived foo" 출력, override 키워드 사용하지 마세요
};
int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);
}