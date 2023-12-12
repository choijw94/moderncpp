// 91 page
int main()
{
	int n = 10;

	// #1. 포인터는 "이중 포인터" 를 만들수 있습니다. 포인터의 포인터
	int *p = &n;
	int* *pp = &p;

	// #2. 레퍼런스의 레퍼런스를 만들수는 없습니다.
	int& r = n;
//	int& &rr = r; // error


	// #3. 타입 추론, 또는 using 사용시는 발생하는 
	//     레퍼런스의 레퍼런스는 아래 규칙으로 계산 됩니다.
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing 규칙. 
	LREF& r3 = n;   // int&  &   => int&
	RREF& r4 = n;   // int&& &	 => int&
	LREF&& r5 = n;  // int&  &&  => int&
	RREF&& r6 = 10; // int&& &&  => int&&


	// 아래 foo 를 생각해 보세요
	foo<int&>(n);

	int x[3] = { 1,2,3 };

	decltype(x[0])& r;  // int& & r;
						// int& r; 인데, 초기값 때문에 에러. 
}

template<typename T> void foo(T a)
{
	T& r = a;	// int& & r = a;
				// int& r = a;
}






