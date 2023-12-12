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
	decltype(*p)	d2;		// *p = 10
	decltype(x[0])	d3; 

	decltype(n) d; 
					

	decltype(n + n) d4; 
	decltype(++n)   d5; 
						
						
	decltype(n++)   d6; 
			
}

// 참고
int x = 0;
int  f1() { return x; } // x의 값 0 반환
int& f2() { return x; } // x의 값 0이 아닌 별명을 반환

int main()
{
	f1() = 10; // error. 0 = 10 의 의미.
	f2() = 10; // ok.    x = 10 의 의미.
}