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

	int arr1[ Factorial(5) ]; 

	int arr2[Factorial(n)]; 
					

	int s2 = Factorial(n); 

	int s = Factorial(5);
}