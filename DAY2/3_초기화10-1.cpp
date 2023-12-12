#include <iostream>
#include <initializer_list>

// const char* s = "hello";
// => "hello" 자체는 "상수 메모리" 라고 했지만, 표준 문서에서 약속된 것은 아닙니다.
// => 표준은 아니지만 대부분 컴파일러가 "상수메모리" 사용

// initializer_list 사용시 생성되는 배열 요소의 메모리 위치는
// => 표준 문서에서 정의되어 있지 않습니다.
// => 컴파일러 마다 다를 수 있는데.. 보통 stack 또는 data 메모리 사용. 

int g = 10;
std::initializer_list<int> gi = { 1,2,3,4 };

int main()
{
	int n = 10;
	std::initializer_list<int> ni = { 5,6,7,8 };

	printf("%p\n", &g);
	printf("%p\n", &(*(gi.begin())));
	printf("%p\n", &n);
	printf("%p\n", &(*(ni.begin())));

}