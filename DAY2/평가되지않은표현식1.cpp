// 평가되지않은표현식1.cpp

int add(int a, int b) { return a + b; }

int main()
{
	// #1. expression(표현식) : 한개의 값으로 결정되는 코드 집합
	int n = 10;
	
	n * 2 + 3;
	add(1, 2);

	// #2. decltype() 의 () 안에는 expression 을 적어야 합니다.
//	decltype(int) d;  // error. int 라는 타입이 아닌 expression 을 넣어야 합니다.


	// #3. decltype(exp) : exp 이 생성하는 값의  타입을 결정하는 것
	decltype( add(1, 2) ) ret = add(1, 2);
}
