// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

// 초기화에서 가장 중요!!

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// std::initializer_list<int>
	// => 초기값을 "배열과 동일한 구조"로 메모리에 만들고
	// => 해당 메모리를 가리키는 "포인터 쌍" 또는 "주소+ 갯수"로 관리
	//    visual studio : 포인터 2개로 구현
	//    g++           : 포인터 1개 + 갯수
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// vector 와 차이점은 뭔가요 ?
	// => 모든 데이타가 힙에 있습니다.

	// 배열과의 차이점은 ?
	// => 배열 자체를 함수 인자로 사용할수 없습니다.

	// 언제 사용하나요 ?
	// => 주로 생성자 인자로 사용. 


	// 사용법은 STL 과 유사합니다.
	auto first = e.begin();

	// 함수인자로 initializer_list 를 사용하면 아래 처럼 전달 가능
	foo({ 1,2,3,4,5 });
	foo({ 1,2,3 });
}


