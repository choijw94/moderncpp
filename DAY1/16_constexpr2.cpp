// constexpr 은 3개가 있습니다.
// 1. constexpr 상수 - C++11 ( 16_constexpr1-1.cpp 참고 )
// 2. constexpr 함수 - C++11
// 3. constexpr if   - C++17



// constexpr function
// => 인자의 값을 컴파일 시간에 알수 있고,
// => 함수가 호출되는 위치가, 컴파일 시간에 값을 알아야 하는 위치라면
// => 함수의 실행을 컴파일 할때 수행해 달라는 것!

constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[ Factorial(5) ]; // ok.  컴파일 하면 "int arr1[120]"

//	int arr2[ Factorial(n) ]; // error. 인자값을 컴파일 할때 알수 없다.
							  //       "배열의 크기" 는 컴파일 할때 알아야 한다.
					

	int s1 = Factorial(n);  // ok. 실행시간에 수행

	int s2 = Factorial(5);  // 컴파일 시간 ? 실행시간 ?
							// => 컴파일러마다 다를수 있음. 표준에서 정의하지 않음.

	const int s3 = Factorial(5); // 위와 동일

	constexpr int s4 = Factorial(5);	// 컴파일 시간!!
										// constexpr 상수는 컴파일 시간에 값을 알아야 한다.
}