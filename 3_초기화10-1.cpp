#include <iostream>
#include <initializer_list>

// const char* s = "hello";
// => "hello" ��ü�� "��� �޸�" ��� ������, ǥ�� �������� ��ӵ� ���� �ƴմϴ�.
// => ǥ���� �ƴ����� ��κ� �����Ϸ��� "����޸�" ���

// initializer_list ���� �����Ǵ� �迭 ����� �޸� ��ġ��
// => ǥ�� �������� ���ǵǾ� ���� �ʽ��ϴ�.
// => �����Ϸ� ���� �ٸ� �� �ִµ�.. ���� stack �Ǵ� data �޸� ���. 

int g = 10;
std::initializer_list<int> gi = { 1,2,3,4 };

int main()
{
	int n = 10;
	std::initializer_list<int> ni = { 5,6,7,8 };

	printf("%p\n", &g);
	printf("%p\n", &(*(gi.begin())));
	printf("%p\n", &n);
	printf("%p\n", &(*(ni.begin())));

}