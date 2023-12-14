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
	T::data * p1;
	T::DWORD* p2;	
}


int main()
{
	Test t;
	foo(t);
}



