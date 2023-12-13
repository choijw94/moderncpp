#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

/*
template<typename F>
void chronometry(F f, int& arg)
{
//	f(arg);	// A
	f(static_cast<int&>(arg));	// B
								// 필요없는 캐스팅이지만, 있어도 에러도 아니고
								// 성능저하도 없습니다.(컴파일 시간에 제거 됩니다.)
								// static_cast : 컴파일러가 하는 캐스팅!
}
template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

// 결국 int&, int&& 버전이 필요하고, int 뿐아니라 다른 타입도 가능해야 합니다.
// T&& 를 사용하면 위 2개를 자동생성할수 있습니다.(int 뿐 아니라 모든 타입에 대해서)
// 그런데, 템플릿으로 함수를 자동생성하려면 함수 구현이 동일해야 합니다.
// (A 코드대신, B 코드로 !!)

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 3;
	
	// 아래 코드를 보고 생성되는 chronometry 함수의 모양과 캐스팅 코드를 예측해 보세요
	chronometry(foo, 10);
	chronometry(goo, n);

}
