// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional> // std::less<>, std::greater<> 가 이미 있습니다.(C++98)
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	
	// #1. 비교 함수를 전달하지 않은 경우 - 오름차순으로 정렬
	std::sort( v.begin(), v.end() );  // 1,2,3,4,5,6,7,8,9,10


	// #2. 비교 함수로 일반함수를 사용 - 비교함수가 인라인 치환 안됨.
	std::sort(v.begin(), v.end(), cmp);


	// #3. 비교 함수로 함수 객체를 사용 - 인라인 치환 가능
	std::less<int> f; // < 로 비교, 

	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>{}); // 임시객체 형태로 전달


	// #4. C++11 부터는 비교 함수로 "람다 표현식" 사용가능.
	// [] : 람다표현식이 시작됨을 알리는 기호, lambda introducer
	//      "익명의 함수" 라고도 합니다.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; }) ;
}





