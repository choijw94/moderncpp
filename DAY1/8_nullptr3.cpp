#include <iostream>

// nullptr �� ��ü!!
// => ���� ����� ���ô�.

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