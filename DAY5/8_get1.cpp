#include <iostream>
using namespace std;

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;

	cout << d.value << endl; // 20

	// 기반 클래스 value 에 접근하려면 기반 클래스 타입으로 캐스팅
	cout << (static_cast<Base>(d)).value << endl;   // 임시객체 생성
	cout << (static_cast<Base&>(d)).value << endl;  // 임시객체 생성안됨. 
		
	(static_cast<Base>(d)).value = 30; // error
	(static_cast<Base&>(d)).value = 30;	

}