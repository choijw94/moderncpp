// 4_���ٱ�Ÿ6-1
#include <vector>

// �Լ� ���ڸ� �б⸸ �Ϸ��� �մϴ�. ������ ���� �ڵ�� ?
void foo(std::vector<int> v) {}			// bad. ���� ������ call by value �������������
void foo(const std::vector<int>& v) {}  // good.

// ������ ���� �ڵ�� ?
void foo(int n)			{ int a = n; } // 1. good






void goo(const int& n)	{ int a = n; } // 2. bad


int a = 10;
foo(a);
goo(a);