int main()
{
	int n = 3;

	// 다음중 에러를 모두 고르세요!
	auto& a1 = n;	// ok
	auto& a2 = 3;	// error.   3 은 rvalue

	// auto 는 T 와 규칙이 동일합니다.
	// 따라서 auto&& 는 T&& 입니다
	// auto&& 는 rvalue reference 아닙니다. forwarding reference
	// => 따라서 아래 코드는 모두 에러 아닙니다.

	auto&& a3 = n;	// n 은 lvalue, auto(T)=int&, auto&&=int& &&.  int&  a3 = n;
	auto&& a4 = 3;  // 3 은 rvalue  auto(T)=int   auto&&=int&&     int&& a4 = 3;
}