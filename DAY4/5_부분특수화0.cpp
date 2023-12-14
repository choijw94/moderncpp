// 2_typename

struct Test
{
	static int data;
	using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
	// "클래스이름::이름" 에서 "이름" 의 의미는 
	// "값" 일수도 있고 "타입" 일수도 있습니다.

//	Test::data  * p;	// data 는 값(static 멤버 데이타), * 는 곱하기 의미
//	Test::DWORD * p;	// DWORD 는 타입, * 는 포인터 변수 p 를 선언하는 의미.


	// 아래 코드를 생각해 보세요
	// dependename name(의존 이름)
	// => template 인자 T에 의존해서 꺼내는 이름
	// => "T::이름" 에서 컴파일러는 무조건 이름을 "값"으로 해석한다.
	// => 아래 코드에서 * 를 곱하기로 해석
//	T::data  * p1;	// error. p1 이 없다.
//	T::DWORD * p2;	// error. p2 가 없다.
					// 그런데, 이 코드의 의도는 포인터 변수 p2의 선언

	// dependename name 이 값이 아닌 타입으로 사용되게 하려면 컴파일러에게
	// 알려주어야 합니다
	typename T::DWORD* p3; // ok
}


int main()
{
	Test t;
	foo(t);
}



