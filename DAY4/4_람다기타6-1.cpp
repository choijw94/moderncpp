// 4_���ٱ�Ÿ6-1
#include <vector>

// �Լ� ���ڸ� �б⸸ �Ϸ��� �մϴ�. ������ ���� �ڵ�� ?
void foo(std::vector<int> v) {}			// bad. ���� ������ call by value �������������
void foo(const std::vector<int>& v) {}  // good.

// ������ ���� �ڵ�� ?
void foo(int n)			{ int a = n; } // 1
void foo(const int& n)	{ int a = n; } // 2