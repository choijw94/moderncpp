// 16_constexpr1-1

int main()
{
	int n = 10;

	// const : read only(immutable)을 만드는 것
	const int c1 = 10; // ok.  literal 로 초기화 해도되고
	const int c2 = n;  // ok.  변수로 초기화도 가능


	// C++11 constexpr : 컴파일 시간에 값을 알수있는 상수을 만드는 것
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error.


	// C++ 공식 용어중 "constant expression" 이 있습니다.
	// => 컴파일 시간에 값을 알수 있는 표현식(expression)
}