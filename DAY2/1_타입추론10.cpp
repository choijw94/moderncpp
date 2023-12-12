int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	// #1. auto vs decltype
//	auto a = x[0];		// int a = x[0]
//	decltype(x[0]) d;	// int& d;     초기값 없으므로 error. 

	// #2.
	auto ret1 = foo();	// foo() 반환 타입이 reference 지만 auto 규칙에 따라
						// int ret1 = foo();

	// decltype(함수 호출식) : 함수 호출의 결과로 나오는 타입. 반환 타입
	//						  함수 선언을 보고 결정.
	decltype(foo()) ret2 = foo();	// int& ret2 = foo()


	// #3. decltype(auto) : C++14 부터 지원
	// => auto 자리에 우변을 놓아 달라!
	// => 우변으로 타입을 추론하는데, 규칙은 decltype 으로 해달라
	decltype(auto) ret3 = foo();
	
	// ret1 은 int 변수, ret2, ret3 은 int& 이므로 x의 별명

	
	
}

