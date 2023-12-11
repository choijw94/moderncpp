#include <unordered_set>

// C 스타일 코드 - typedef 
//typedef int DWORD;
//typedef void(*F)(); 


// C++11 부터는 typedef 보다 using 이 편리합니다.
// => 아래 2줄이 위 코드와 완전히 동일합니다.
using DWORD = int;
using F     = void(*)();


// typedef 가 있는데 왜 새로운 using 을 만들었나요 ??
// 1. using 이 typedef 보다 보기 좋습니다.
// 2. typedef : 타입의 별명만 만들수 있습니다.
//    using   : 타입의 별명 + 템플릿의 별명을 만들수 있습니다.(2번예제 참고)

int main()
{
	DWORD n;	// int n
	F     f;	// void (*f)()
}