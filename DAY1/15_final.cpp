class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// final : ���̻� override �Ҽ� �������Ҷ� ���
	virtual void foo()      override final {} 
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

class Derived2 : public Derived
{
public:
	virtual void foo()      override {} // error. final!!!
	virtual void goo(int a) override {} // ok
	virtual void hoo()      override {} // ok
};

int main()
{
}