// 6_enable_if1.cpp
// 아래 코드(enable_if) 는 이미 C++11 표준에 있습니다. 아래 코드와 거의 동일한 구현사용
template<bool, typename T = void > struct enable_if
{
	using type = T;
};

template<typename T> struct enable_if<false, T> 
{
	// 핵심 : type 멤버가 없다!!
};

// enable_if 사용법 : enable_if<bool값, 타입>
// 핵심 : 1번째 인자가 false 인 경우 부분 특수화 버전 제공

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2 인데, void 형 변수를 만들수 없으므로 error
	enable_if<false, int>::type n3; // "::type" 이 없으므로 error

	// enable_if 꼭 기억할것
	// 1. enable_if<false, "타입">::type  은 에러.. "type" 이 없다.
	// 2. enable_if<true,  "타입">::type  의 결과로 나오는 타입은 "타입"
	// 3. enable_if<true>::type           의 결과로 나오는 타입은 "void"
}