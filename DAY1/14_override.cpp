// 14_override  - 44 page

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
	// 가상 함수 재정의시 실수(오타) 발생해도 컴파일 에러가 아닙니다.
	// => 컴파일러는 새로운 가상 함수를 만들었다고 생각
//	virtual void fooo() {}
//	virtual void goo(double a) {}
//	virtual void hoo() const  {}

	// 위와 같은 현상 때문에 버그가 많았습니다.
	// => C++11 부터 override 키워드 제공
	// => 새로운 가상함수가 아니라, 기존 가상함수를 override 한다고 알리는 것
	// => 오타 발생시 error
	virtual void fooo()        override {}
	virtual void goo(double a) override {}
	virtual void hoo() const   override {}

};


int main()
{
}