// 1_�ʱ�ȭ8 - 62page
#include <iostream>
#include <initializer_list> // �ٽ�

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// std::initializer_list<int>
	// => �ʱⰪ�� "�迭�� ������ ����"�� �޸𸮿� �����
	// => �ش� �޸𸮸� ����Ű�� "������ ��" �Ǵ� "�ּ�+ ����"�� ����
	std::initializer_list<int> e = { 1,2,3,4,5 };
}


