// 4_람다기타6-1
#include <vector>

// 함수 인자를 읽기만 하려고 합니다. 다음중 좋은 코드는 ?
void foo(std::vector<int> v) {}			// bad. 절대 값으로 call by value 사용하지마세요
void foo(const std::vector<int>& v) {}  // good.

// 다음중 좋은 코드는 ?
void foo(int n)			{ int a = n; } // 1. good






void goo(const int& n)	{ int a = n; } // 2. bad


int a = 10;
foo(a);
goo(a);