// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()	// void foo( Test* this) 
	{
		// 람다 표현식에서 멤버 데이타에 접근하고 싶다.
//		auto f = [](int a) { return a + data; }; // error
//		auto f = [data](int a) { return a + data; }; // error. data 는 지역변수아님

		// 람다표현식에서 멤버 데이타 접근하려면 this 를 캡쳐하면 됩니다.
		auto f = [this](int a) { return a + data; }; // ok

	}
};

int main()
{
	Test t;
	t.foo(); // foo(&t)
}

