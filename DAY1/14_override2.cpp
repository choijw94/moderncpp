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
	// foo 재정의하세요 "Derived foo" 출력, override 키워드 사용하지 마세요
	virtual void foo(const int* a)
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);	// "Derived foo" 나오도록 Derived 안에 foo 만드세요
}