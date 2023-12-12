// 1_�ʱ�ȭ8 - 62page
#include <iostream>
#include <initializer_list> // �ٽ�

// �ʱ�ȭ���� ���� �߿�!!

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// std::initializer_list<int>
	// => �ʱⰪ�� "�迭�� ������ ����"�� �޸𸮿� �����
	// => �ش� �޸𸮸� ����Ű�� "������ ��" �Ǵ� "�ּ�+ ����"�� ����
	//    visual studio : ������ 2���� ����
	//    g++           : ������ 1�� + ����
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// vector �� �������� ������ ?
	// => ��� ����Ÿ�� ���� �ֽ��ϴ�.

	// �迭���� �������� ?
	// => �迭 ��ü�� �Լ� ���ڷ� ����Ҽ� �����ϴ�.

	// ���� ����ϳ��� ?
	// => �ַ� ������ ���ڷ� ���. 


	// ������ STL �� �����մϴ�.
	auto first = e.begin();

	// �Լ����ڷ� initializer_list �� ����ϸ� �Ʒ� ó�� ���� ����
	foo({ 1,2,3,4,5 });
	foo({ 1,2,3 });
}


