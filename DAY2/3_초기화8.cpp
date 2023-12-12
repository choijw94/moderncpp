// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// std::initializer_list<int>
	// => 초기값을 "배열과 동일한 구조"로 메모리에 만들고
	// => 해당 메모리를 가리키는 "포인터 쌍" 또는 "주소+ 갯수"로 관리
	std::initializer_list<int> e = { 1,2,3,4,5 };
}


