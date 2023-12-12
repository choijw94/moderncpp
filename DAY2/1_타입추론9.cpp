// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// decltype 규칙 1. 심볼의 이름만 있을때, 해당 변수와 동일타입으로 결정
	decltype(p)		d1; // int* d1


	// decltype(exp) 규칙2. exp 에 "심볼이름과 연산자등의 표현식"이 같이 있을때
	//				 exp 가 등호의 왼쪽에 올수 있다면 "reference" 타입
	//               그렇지 않다면 "value" 타입 

	decltype(*p)	d2;		// *p = 10 가 가능하므로, int& d2, 초기값 문제로 error
	decltype(x[0])	d3;		// x[0] = 10  가능		 int& d3, 초기값 문제로 error

	decltype(n) d;			// n = 10 도 가능하지만, 심볼의 이름만 있으므로 규칙 1 적용
							// int d

	decltype(n + n) d4;		// n + n = 10 는 에러!   int d4;

	decltype(++n)   d5;		// ++n = 10 는 에러 아님  int& d5. 초기값 문제로 error						
						
	decltype(n++)   d6;		// n++ = 10 은 에러.     int d6			

	++n; // 이 코드를 자세히 생각해 봅시다.
		 // operator++(n)

	n++; // operator++(n, int)
}
/*
// operator++ 을 primitive 타입에 대해서 overloading 할수 없지만, 설명을 위해
// 전위형 ++
int& operator++(int& a)
{
	a = a + 1;
	return a;
}
int operator++(int& a, int)
{
	int temp = a;
	a = a + 1;
	return temp;
}
*/



// 참고
/*
int x = 0;
int  f1() { return x; } // x의 값 0 반환
int& f2() { return x; } // x의 값 0이 아닌 별명을 반환

int main()
{
	f1() = 10; // error. 0 = 10 의 의미.
	f2() = 10; // ok.    x = 10 의 의미.
}
*/