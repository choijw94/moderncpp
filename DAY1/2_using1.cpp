#include <unordered_set>

// C ��Ÿ�� �ڵ� - typedef 
//typedef int DWORD;
//typedef void(*F)(); 


// C++11 ���ʹ� typedef ���� using �� ���մϴ�.
using DWORD = int;
using F     = void(*)();

int main()
{
	DWORD n;	// int n
	F     f;	// void (*f)()
}