#include <unordered_set>

// C ��Ÿ�� �ڵ� - typedef 
//typedef int DWORD;
//typedef void(*F)(); 


// C++11 ���ʹ� typedef ���� using �� ���մϴ�.
// => �Ʒ� 2���� �� �ڵ�� ������ �����մϴ�.
using DWORD = int;
using F     = void(*)();


// typedef �� �ִµ� �� ���ο� using �� ��������� ??
// 1. using �� typedef ���� ���� �����ϴ�.
// 2. typedef : Ÿ���� ���� ����� �ֽ��ϴ�.
//    using   : Ÿ���� ���� + ���ø��� ������ ����� �ֽ��ϴ�.(2������ ����)

int main()
{
	DWORD n;	// int n
	F     f;	// void (*f)()
}