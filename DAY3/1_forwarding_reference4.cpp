// T& : 모든 타입(임의타입)의 lvalue 만 받을수 있다.

template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// #1. 타입인자를 명시적으로 전달하는 경우
	// => 함수 인자를 보고 T를 추론하는 것이 아니라, 사용자가 전달한 타입사용
	f3<int>(n);		// T = int		T& = int&			f3(int& a) 함수 생성
	f3<int&>(n);	// T = int&		T& = int& &			f3(int& a) 함수 생성
	f3<int&&>(n);	// T = int&&	T& = int&& &		f3(int& a) 함수 생성


	// #2. 타입을 명시적으로 전달하지 않는 경우
	// => 함수의 인자를 보고, 타입을 추론. 
	f3(3);	// 3은 int. T를 int, int&, int&& 중 어떤것으로 해도
			// 생성된 함수는 3을 받을수 없다.
			// 함수를 만들수 없으므로 error.

	f3(n);	// T=int 로 결정해서, f3(int& a) 인 함수 생성
}
