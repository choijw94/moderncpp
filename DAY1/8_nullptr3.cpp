#include <iostream>

// nullptr 의 정체!!
// => 직접 만들어 봅시다.

void foo(int* p) {}
void goo(char* p) {}

struct mynullptr_t
{
};
mynullptr_t mynullptr;

int main()
{
	foo(mynullptr);
	goo(mynullptr);
}