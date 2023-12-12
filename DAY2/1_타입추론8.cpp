// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	auto a = r; // int a = r;
				// 즉, auto 는 우변의 reference 를 제거하고 타입 결정

	// dectype(exp) 규칙 1. exp 에 심볼의 이름만 있을때
	// => 심볼의 선언을 보고, 동일 타입을 결정
	decltype(n) d1; // int d1
	decltype(r) d2; // int& d2       인데, 초기값이 없으므로 error
	decltype(c) d3; // const int d3        초기값이 없으므로 error
	decltype(p) d4; // int* d4
}