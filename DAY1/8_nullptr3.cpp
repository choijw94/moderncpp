#include <iostream>

// nullptr �� ��ü!!
// => ���� ����� ���ô�.
// 1. boost ��� ���̺귯������ ������ �Ʒ� mynullptr_t Ŭ������ ���� ���.
// 2. C++11 ǥ���� ���鶧 boost �� nullptr �� ä�õ�.
// => ��, ǥ���� �Ʒ��� ���� ����ü�� �ƴ� "nullptr" ��ü�� Ű����.

void foo(int* p) {}
void goo(char* p) {}

//====================================
struct mynullptr_t
{
	// ��ȯ ������ : ��ü�� �ٸ� Ÿ������ �Ͻ��� ��ȯ�� �ʿ��Ҷ� ȣ��Ǵ� �Լ�
//	operator int* () { return 0; }
//	operator char* () { return 0; }

	template<typename T>
	inline operator T* () const { return 0; }
};
mynullptr_t mynullptr;
//====================================

int main()
{
	foo(mynullptr); // mynullptr.operator int*() ��� ��� �Լ� �ʿ�

	goo(mynullptr);
}