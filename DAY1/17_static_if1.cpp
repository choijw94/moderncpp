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

	// 지연된 인스턴스화
	// => 클래스 템플릿의 멤버 함수는 사용된 멤버 함수만 인스턴스화에 포함됩니다.
	// => 아래 foo 처럼 사용한것만, 실제 클래스의 멤버로 생성됩니다.
	a.foo();
}