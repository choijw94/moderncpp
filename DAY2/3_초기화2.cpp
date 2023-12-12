#include <complex>

int main()
{
	// C++98 시절
	// => 객체의 종류에 따라 초기화 방법이 다름.
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);


	// C++11. "일관된 초기화(uniform initialization)" 문법
	// => 모든 종류의 객체를 한가지 일관된 방식으로 초기화 할수 있다.
	// => "중괄호 초기화(brace initialization)" 이라고도 합니다.

	int n2 = { 10 };
	int x2[2] = { 1,2 };
	std::complex<double> c2 = { 1, 2 };


	// = 이 없어도 됩니다.
	int n3{ 10 };
	int x3[2]{ 1,2 };
	std::complex<double> c3{ 1, 2 };

	// direct(직접) initialization : = 이 없는 초기화
	// copy(복사) initialization   : = 이 있는 초기화
}












