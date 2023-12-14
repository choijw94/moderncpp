int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;
	
	// 아래 코드가 에러가 발생하는게 좋으세요 ? 에러가 아닌게 좋으세요 ?
	swap(n, d); // int 와 double 의 swap 은 논리적으로 맞지 않습니다.
				// 에러가 좋습니다.
				// 그런데, 에러 아닙니다.
				// "generic lambda" 는 인자가 모두 별도의 템플릿 인자

	// 해결책 : 1, 2번째 인자가 같아야 한다!!! 가 필요 합니다
	// => C++20 부터 "template 람다" 문법 추가.

	auto swap2 = []<typename T>(T& a, T& b) {  }; // 구현 생략.
	
	swap2(n, d); // error
}