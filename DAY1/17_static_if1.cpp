/*
// 아래 코드가 왜 에러인지 생각해 보세요 ?
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;	// error. data 는 int 타입이므로 * 연산 할수 없다.
	}
};
int main()
{
	A a;
}
*/

template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10;
	}
};

int main()
{
	A<int> a;

	// 지연된 인스턴스화(C++98)
	// => 클래스 템플릿의 멤버 함수는 사용된 멤버 함수만 인스턴스화에 포함됩니다.
	// => 아래 foo 처럼 사용한것만, 실제 클래스의 멤버로 생성됩니다.
	a.foo();
}

// 템플릿은 2번 컴파일 됩니다.
// 1. 템플릿 자체를 먼저 컴파일 하고
// 2. 인스턴스화된 클래스 자체를 다시 컴파일 합니다
// => 인스턴스화는 "컴파일 시에 사용하는 코드"를 보고 컴파일 시간에 인스턴스화 됩니다.