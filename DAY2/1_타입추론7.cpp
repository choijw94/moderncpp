// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);
	// T a = 10;  // 이렇게 생각해 보면 아래 코드와 동일합니다.
	auto a = 10;  // auto 추론 규칙은 템플릿과 거의 유사 합니다.


	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	//"T a1 = n" 의 의미 이므로. 규칙 1. 값으로 받을때 을 적용하면 됩니다.
	//							우변(인자)의 const, volatile, reference 모두 제거
	auto a1 = n;  // a1 : int a1 = n
	auto a2 = r;  // a2 : int a2 = r
	auto a3 = c;  // a3 : int a3 = c
	auto a4 = cr; // a4 : int a4 = cr


	// auto& 이므로 T& 와 동일. 규칙 2. 우변(인자)의 reference 만 제거하고 결정
	auto& a5 = n;  // auto = int		a5 = int&
	auto& a6 = r;  // auto = int		a6 = int&
	auto& a7 = c;  // auto = const int	a7 = const int&
	auto& a8 = cr; // auto = const int  a8 = const int&

	
	int x[3] = { 1,2,3 };

	// x : int[3]
	auto  a11 = x;	// 배열로 결정하면 "int a11[3] = x;" 이므로 에러.
					// 그래서         "int* a11 = x;" 로 결정
					// auto = int*     a11 = int*

	auto& a12 = x;  // auto = int[3]   a12 = int(&)[3]
}


