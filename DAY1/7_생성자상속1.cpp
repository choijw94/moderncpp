// 7_생성자상속1 - 26page

class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};

class Derived : public Base
{
public:
	// C++11 부터는 생성자도 상속받을수 있습니다
	// => using 클래스이름::생성자이름;
	using Base::Base;  
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}
