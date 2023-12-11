#include <unordered_set>

// C 스타일 코드 - typedef 
//typedef int DWORD;
//typedef void(*F)(); 


// C++11 부터는 typedef 보다 using 이 편리합니다.
using DWORD = int;
using F     = void(*)();

int main()
{
	DWORD n;	// int n
	F     f;	// void (*f)()
}